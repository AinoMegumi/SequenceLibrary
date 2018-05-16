// 等比数列
#ifndef __COMMONRATIOSEQUENCE_HPP__
#define __COMMONRATIOSEQUENCE_HPP__
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <type_traits>

template<typename T = int, std::enable_if_t<std::is_arithmetic<T>::value, std::nullptr_t> = nullptr>
class CommonRatioSequence {
private:
	T CommonRatio;
	std::vector<T> arr;
public:
	CommonRatioSequence(const T FirstTerm, const T CommonRatio) : CommonRatio(CommonRatio) { this->arr.emplace_back(FirstTerm); }
	CommonRatioSequence(const CommonRatioSequence&) = delete;
	CommonRatioSequence(CommonRatioSequence&&) = default;
	CommonRatioSequence& operator = (const CommonRatioSequence&) = delete;
	CommonRatioSequence& operator = (CommonRatioSequence&&) = delete;
	T GetTerm(const size_t TermNum) {
		if (TermNum <= this->arr.size()) return this->arr[TermNum - 1];
		// pow関数の戻り値が浮動小数点型だったから律儀に計算させた
		this->arr.reserve(TermNum);
		for (size_t i = this->arr.size(); i < TermNum; i++) this->arr.push_back(this->arr.back() * this->CommonRatio);
		return this->arr.back();
	}
	T GetTotal(const size_t Start, const size_t End) {
		const std::pair<size_t, size_t> n = std::minmax(Start, End);
		this->GetTerm(n.second);
		return std::accumulate(this->arr.begin() + n.first - 1, this->arr.begin() + n.second, T{});
	}
	std::vector<T> CreateSequenceArray(const size_t LastTermNum) {
		this->GetTerm(LastTermNum);
		if (this->arr.size() == LastTermNum + 1) return this->arr;
		else return{ this->arr.begin(), this->arr.begin() + LastTermNum };
	}
};

#endif
