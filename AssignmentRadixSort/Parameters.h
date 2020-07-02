#pragma once

#include <cstdint>
#include <limits>

/// Collection of compile-time parameters.
template <typename _DataType>
struct AlgorithmParameters
{
	using DataType = _DataType;
	///////////////////////////////////////////////////////
	// these parameters can be changed
	static constexpr auto _NUM_ITEMS_PER_GROUP = 64U; // number of items in a group
	static constexpr auto _NUM_GROUPS = 16U; // the number of virtual processors is _NUM_ITEMS_PER_GROUP * _NUM_GROUPS
	static constexpr auto _NUM_HISTOSPLIT = 512U; // number of splits of the histogram
	//static constexpr uint32_t _TOTALBITS = 32;  // number of bits for the integer in the list (max=32)
	static constexpr uint32_t _TOTALBITS = sizeof(DataType) << 3U;  // number of bits for the integer in
	static constexpr auto _NUM_BITS_PER_RADIX = 4U;  // number of bits in the radix
	// max size of the sorted vector
	// it has to be divisible by  _NUM_ITEMS_PER_GROUP * _NUM_GROUPS
	// (for other sizes, pad the list with big values)
	static constexpr auto _NUM_MAX_INPUT_ELEMS = (1U << 25U);  // maximal size of the list
	//#define PERMUT  // store the final permutation
	////////////////////////////////////////////////////////

	// the following parameters are computed from the previous
	static constexpr auto _RADIX = (1U << _NUM_BITS_PER_RADIX); //  radix  = 2^_NUM_BITS_RADIX
	static constexpr auto _NUM_PASSES = (_TOTALBITS / _NUM_BITS_PER_RADIX); // number of needed passes to sort the list
	static constexpr auto _HISTOSIZE = (_NUM_ITEMS_PER_GROUP * _NUM_GROUPS * _RADIX); // size of the histogram
	// maximal value of integers for the sort to be correct
	//static constexpr DataType _MAXINT = (1ULL << (_TOTALBITS - 1ULL));
	static constexpr DataType _MAXINT = std::numeric_limits<DataType>::max();

	static constexpr auto _NUM_PERFORMANCE_ITERATIONS = 5U; // number of iterations for performance testing
};

