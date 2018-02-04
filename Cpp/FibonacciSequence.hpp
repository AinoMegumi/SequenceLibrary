// フィボナッチ数列
#ifndef __FIBONACCISEQUENCE_HPP__
#define __FIBONACCISEQUENCE_HPP__
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

template<typename T> class FibonacciSequence {
private:
	std::vector<T> arr;
public:
	FibonacciSequence(const T ZeroTerm = 0, const T FirstTerm = 1) {
		this->arr.push_back(0);
		this->arr.push_back(FirstTerm);
	}
	FibonacciSequence(const FibonacciSequence&) = delete;
	FibonacciSequence(FibonacciSequence&&) = default;
	FibonacciSequence& operator = (const FibonacciSequence&) = delete;
	FibonacciSequence& operator = (FibonacciSequence&&) = delete;
	T GetTerm(const size_t TermNum) {
		// すでに計算された部分にあればさっさと返す
		if (TermNum <= this->arr.size() - 1) return this->arr[TermNum];
		// ないなら計算する
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size() - 1; i <= TermNum - 1; i++) this->arr.push_back(this->arr[i] + this->arr[i - 1]);
		return this->arr.back();
	}
	T GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		this->GetTerm(n.second);
		return std::accumulate(this->arr.begin() + n.first, this->arr.begin() + n.second + 1, T{});
	}
	std::vector<T> CreateSequenceArray(const size_t LastTermNum) {
		this->GetTerm(LastTermNum);
		if (this->arr.size() == LastTermNum + 1) return this->arr;
		else return{ this->arr.begin(), this->arr.begin() + LastTermNum + 1 };
	}
};
#endif
