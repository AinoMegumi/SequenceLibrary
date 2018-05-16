// シルベスターの数列
#ifndef __SYLVESTERSEQUENCE_HPP__
#define __SYLVESTERSEQUENCE_HPP__
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <type_traits>

template<typename T = unsigned long, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
class SylvesterSequence {
private:
	std::vector<T> arr;
public:
	SylvesterSequence() { this->arr.emplace_back(2); }
	SylvesterSequence(const SylvesterSequence&) = delete;
	SylvesterSequence(SylvesterSequence&&) = default;
	SylvesterSequence& operator = (const SylvesterSequence&) = delete;
	SylvesterSequence& operator = (SylvesterSequence&&) = delete;
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	U GetTerm(const size_t TermNum) {
		if (TermNum <= this->arr.size() - 1) return static_cast<U>(this->arr[TermNum]);
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size() - 1; i <= TermNum - 1; i++) this->arr.push_back((this->arr[i] * this->arr[i]) - this->arr[i] + 1);
		return static_cast<U>(this->arr.back());
	}
	template<typename U = T, std::enable_if_t<std::is_arithmetic<U>::value, std::nullptr_t> = nullptr>
	U GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		this->GetTerm(n.second);
		return static_cast<U>(std::accumulate(this->arr.begin() + n.first, this->arr.begin() + n.second + 1, T{}));
	}
	std::vector<T> CreateSequenceArray(const size_t LastTermNum) {
		this->GetTerm(LastTermNum);
		if (this->arr.size() == LastTermNum + 1) return this->arr;
		else return{ this->arr.begin(), this->arr.begin() + LastTermNum + 1 };
	}
};

#endif
