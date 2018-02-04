// ペラン数
#ifndef __PERRINNUMBER_HPP__
#define __PERRINNUMBER_HPP__
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

class PerrinNumber {
private:
	std::vector<int> arr;
public:
	PerrinNumber() {
		this->arr.emplace_back(3);
		this->arr.emplace_back(0);
		this->arr.emplace_back(2);
	}
	int GetTerm(const size_t TermNum) {
		// すでに計算された部分にあればさっさと返す
		bool flag = TermNum <= this->arr.size() + 1;
		if (TermNum <= this->arr.size() - 1) return this->arr[TermNum];
		// ないなら計算する
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size() - 1; i <= TermNum - 1; i++) this->arr.push_back(this->arr[i - 1] + this->arr[i - 2]);
		return this->arr.back();
	}
	int GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		this->GetTerm(n.second);
		return std::accumulate(this->arr.begin() + n.first, this->arr.begin() + n.second + 1, int{});
	}
	std::vector<int> CreateSequenceArray(const size_t LastTermNum) {
		this->GetTerm(LastTermNum);
		if (this->arr.size() == LastTermNum + 1) return this->arr;
		else return{ this->arr.begin(), this->arr.begin() + LastTermNum + 1 };
	}
};
#endif
