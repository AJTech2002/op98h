#pragma once

#include <vector>

#include "DefineDllForWin.h"

#include "CloApiData.h"

namespace Marvelous
{
	class View3DBase;
	class SceneGraph;
	class PatternEditor;
	class Library;
}

namespace CLOAPI
{
using namespace std;

	class MV_CLO_INTERFACE_API ImportAPIInterface {
	public:
		/// @fn ImportFile(const string& filePath)
		/// @brief Load File (zprj, zpac, avt, obj, fbx, zcmr). This function will show up the dialog per the file type.
		/// @param filePath: the input file path to load
		/// @return if it succeeds, return true.
		virtual bool ImportFile(const string& filePath) { return true; }

		/// @fn ImportFileW(const wstring& filePath)
		/// @brief Load File (zprj, zpac, avt, obj, fbx, zcmr). This function will show up the dialog per the file type.
		/// @param filePath: the input file path to load
		/// @return if it succeeds, return true.
		virtual bool ImportFileW(const wstring& filePath) { return true; }

		/// @fn ImportZprj(const string& filePath, const Marvelous::ImportZPRJOption& loadOption)
		/// @brief Load File (zprj, zpac, avt, obj, fbx, zcmr) without the dialog but the loadOption
		/// @param filePath: the input file path to load
		/// @param loadOption: the options to load the file
		/// @return if it succeeds, return true.
		virtual bool ImportZprj(const string& filePath, const Marvelous::ImportZPRJOption& loadOption) { return true; }

		/// @fn ImportZprjW(const wstring& filePath, const Marvelous::ImportZPRJOption& loadOption)
		/// @brief Load File (zprj, zpac, avt, obj, fbx, zcmr) without the dialog but the loadOption
		/// @param filePath: the input file path to load
		/// @param loadOption: the options to load the file
		/// @return if it succeeds, return true.
		virtual bool ImportZprjW(const wstring& filePath, const Marvelous::ImportZPRJOption& loadOption) { return true; }

		/// @fn ImportGarmentInformation(const string& filePath)
		/// @brief Load Garment Information (json)
		/// @param filePath: the input file to load the garment information (.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformation(const string& filePath) { return true; }

		/// @fn ImportGarmentInformationW(const wstring& filePath)
		/// @brief Load Garment Information (json)
		/// @param filePath: the input file to load the garment information (.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformationW(const wstring& filePath) { return true; }

		/// @fn ImportGarmentInformationConfigData(const string& filePath)
		/// @brief Load Garment Information Configuration (json)		
		/// @param filePath: the input file to load the garment information configuration data(.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformationConfigData(const string& filePath) { return true; }

		/// @fn ImportGarmentInformationConfigDataW(const wstring& filePath)
		/// @brief Load Garment Information Configuration (json)		
		/// @param filePath: the input file to load the garment information configuration data(.json)
		/// @return if it succeeds, return true.
		virtual bool ImportGarmentInformationConfigDataW(const wstring& filePath) { return true; }
	};
}
