// ペラン数
#ifndef __PERRINNUMBER_HPP__
#define __PERRINNUMBER_HPP__
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <type_traits>

template<typename T = unsigned long, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
class PerrinNumber {
private:
	std::vector<T> arr;
public:
	PerrinNumber() {
		this->arr.emplace_back(3);
		this->arr.emplace_back(0);
		this->arr.emplace_back(2);
	}
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	U GetTerm(const size_t TermNum) {
		// すでに計算された部分にあればさっさと返す
		if (TermNum <= this->arr.size()) return static_cast<U>(this->arr[TermNum]);
		// ないなら計算する
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size() - 1; i <= TermNum - 1; i++) this->arr.push_back(this->arr[i - 1] + this->arr[i - 2]);
		return static_cast<U>(this->arr.back());
	}
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	U GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		return static_cast<U>(std::accumulate(this->arr.begin() + n.first, this->arr.begin() + n.second + 1, T{}));
	}
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	std::vector<T> CreateSequenceArray(const size_t LastTermNum) {
		this->GetTerm(LastTermNum);
		if (this->arr.size() == LastTermNum + 1) return this->arr;
		else return{ this->arr.begin(), this->arr.begin() + LastTermNum + 1 };
	}
};

#endif
