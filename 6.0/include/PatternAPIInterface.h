#pragma once

#include <vector>

#include "DefineDllForWin.h"


namespace CLOAPI
{
    using namespace std;

	class MV_CLO_INTERFACE_API PatternAPIInterface {
	public:

		/// @fn GetPatternSize()
		/// @brief Get the number of patterns
		///	@return return the number of patterns on the pattern editor and avatar window
		virtual int GetPatternSize() { return 0; } // deprecated. please use 'GetPatternCount()' function

		/// @fn GetPatternIndex(const string& patternName)
		/// @brief Get the pattern index which is using the pattern name
		/// @param patternName: the input pattern name to get the pattern index
		/// @return pattern index
		virtual int GetPatternIndex(const string& patternName) { return 0; }

		/// @fn GetPatternIndexW(const wstring& patternName)
		/// @brief Get the pattern index which is using the pattern name
		/// @param patternName: the pattern name to get the pattern index
		/// @return pattern index
		virtual int GetPatternIndexW(const wstring& patternName) { return 0; }
		
		/// @fn GetPatternInformation(int patternIndex)
		/// @brief Get the pattern information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern information
		/// @return json string for pattern information
		virtual string GetPatternInformation(int patternIndex) { return ""; }

		/// @fn GetPatternInformationW(int patternIndex)
		/// @brief Get the pattern information which is using for pattern index
		/// @param patternIndex: the pattern index to get the pattern information
		/// @return json string for pattern information
		virtual wstring GetPatternInformationW(int patternIndex) { return L""; }

		/// @fn GetPatternCount()
		/// @brief Get the number of patterns
		///	@return return the number of patterns on the pattern editor and avatar window
		virtual int GetPatternCount() { return 0; }
	};
}
