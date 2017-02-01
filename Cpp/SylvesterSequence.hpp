// シルベスターの数列
#ifndef __SYLVESTERSEQUENCE_HPP__
#define __SYLVESTERSEQUENCE_HPP__
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

class SylvesterSequence {
private:
	std::vector<int> arr;
public:
	SylvesterSequence() { this->arr.emplace_back(0); }
	SylvesterSequence(const SylvesterSequence&) = delete;
	SylvesterSequence(SylvesterSequence&&) = default;
	SylvesterSequence& operator = (const SylvesterSequence&) = delete;
	SylvesterSequence& operator = (SylvesterSequence&&) = delete;
	int GetTerm(const size_t TermNum) {
		if (TermNum <= this->arr.size() - 1) return this->arr[TermNum];
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size() - 1; i <= TermNum - 1; i++) this->arr.push_back(i * i - i + 1);
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
