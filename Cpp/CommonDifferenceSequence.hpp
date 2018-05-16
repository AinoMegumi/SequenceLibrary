// 等差数列
#ifndef __COMMONDIFFERENCESEQUENCE_HPP__
#define __COMMONDIFFERENCESEQUENCE_HPP__
#include <vector>
#include <utility>
#include <algorithm>
#include <type_traits>

template<typename T = int, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
class CommonDifferenceSequence {
private:
	T FirstTerm, CommonDifference;
public:
	CommonDifferenceSequence(const T FirstTerm, const T CommonDifference) : FirstTerm(FirstTerm), CommonDifference(CommonDifference) {}
	T GetTerm(const size_t TermNum) { return this->FirstTerm + (TermNum - 1) * this->CommonDifference; }
	T GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		return (n.second - n.first + 1) * (this->GetTerm(Start) + this->GetTerm(End)) / 2;
	}
	std::vector<T> CreateSequenceArray(const size_t LastTermNum) {
		std::vector<T> arr;
		arr.reserve(LastTermNum - 1);
		for (size_t i = 0; i < LastTermNum; i++) arr.push_back(this->GetTerm(i + 1));
		return arr;
	}
};
#endif
