// フィボナッチ数列
#ifndef __FIBONACCISEQUENCE_HPP__
#define __FIBONACCISEQUENCE_HPP__
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <type_traits>

template<typename T = unsigned long, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
class FibonacciSequence {
private:
	std::vector<T> arr;
public:
	FibonacciSequence(const size_t CreateTermNum = 10) {
		this->arr.emplace_back(0);
		this->arr.emplace_back(1);
		if (CreateTermNum >= 2) {
			for (int i = 2; i <= CreateTermNum; i++)
				this->arr.emplace_back(this->arr.back() + this->arr.at(this->arr.size() - 2));
		}
	}
	FibonacciSequence(const FibonacciSequence&) = delete;
	FibonacciSequence(FibonacciSequence&&) = default;
	FibonacciSequence& operator = (const FibonacciSequence&) = delete;
	FibonacciSequence& operator = (FibonacciSequence&&) = delete;
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	U GetTerm(const size_t TermNum) {
		// すでに計算された部分にあればさっさと返す
		if (TermNum <= this->arr.size()) return static_cast<U>(this->arr[TermNum]);
		// ないなら計算する
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size() - 1; i <= TermNum - 1; i++) this->arr.push_back(this->arr[i] + this->arr[i - 1]);
		return static_cast<U>(this->arr.back());
	}
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	U GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		return static_cast<T>(std::accumulate(this->arr.begin() + n.first, this->arr.begin() + n.second + 1, T{}));
	}
	std::vector<T> CreateSequenceArray(const size_t LastTermNum) {
		this->GetTerm(LastTermNum);
		if (this->arr.size() == LastTermNum + 1) return this->arr;
		else return { this->arr.begin(), this->arr.begin() + LastTermNum + 1 };
	}
};
#endif
