#pragma once

#include <vector>

#include "DefineDllForWin.h"

namespace CLOAPI
{
using namespace std;

	class MV_CLO_INTERFACE_API FabricAPIInterface {
	public:
		/// @fn GetFabricCount()
		/// @brief Get the number of fabrics
		/// @return the number of fabric in object browser for the current project.
		virtual unsigned int GetFabricCount() { return 0; }

		/// @fn GetCurrentFabricIndex()
		/// @brief Get the index of the selected Fabric
		/// @return the index of selected fabric in object browser for the current project..
		virtual unsigned int GetCurrentFabricIndex() { return 0; }

		/// @fn ExportZFab()
		/// @brief Export ZFab which cotains the fabric data selected in the object browser
		/// @return Output file path;output files will be created in CLO temporary folder. If an error occurs, return empty string.
		virtual string ExportZFab() { return ""; }

		/// @fn ExportZFab(const string& filePath)
		/// @brief Export Zfab which cotains the fabric data selected in the object browser
		/// @param filePath: output file path
		/// @return Output file path. If an error occurs, return empty string. 
		virtual string ExportZFab(const string& filePath) { return ""; }

		/// @fn ExportZFab(const string& filePath, const int& index)
		/// @brief Export ZFab which cotains the fabric data in the index of the object browser
		/// @param filePath: output file path
		/// @param index: target fabric index on the object browser to export
		/// @return Output file path. If an error occurs, return empty string. 
		virtual string ExportZFab(const string& filePath, const int& index) { return ""; }

		/// @fn ExportZFabW(const wstring& filePath, const int& index)
		/// @brief Export ZFab file which cotains the fabric data in the index of the object browser
		/// @param filePath: output file path
		/// @param index: target fabric index on the object browser to export
		/// @return Output file path. If an error occurs, return empty string. 
		virtual wstring ExportZFabW(const wstring& filePath, const int& index) { return L""; }
		
		/// @fn ExportFabric(const string& filePath)
		/// @brief Export the selected fabric to the file(.jfab or .zfab)		
		/// @param filePath: output file path		
		/// @return Output file path. If an error occurs, return empty string.
		virtual string ExportFabric(const string& filePath) { return ""; }

		/// @fn ExportFabric(const string& filePath, const int& index)
		/// @brief Export the selected fabric to the file(.jfab or .zfab)		
		/// @param filePath: output file path		
		/// @param index: target fabric index on the object browser to export
		/// @return Output file path. If an error occurs, return empty string.
		virtual string ExportFabric(const string& filePath, const int& index) { return ""; }

		/// @fn ExportFabricW(const wstring& filePath, const int& index)
		/// @brief Export the selected fabric to the file(.jfab or .zfab)		
		/// @param filePath: output file path		
		/// @param index: target fabric index on the object browser to export
		/// @return Output file path. If an error occurs, return empty string.
		virtual wstring ExportFabricW(const wstring& filePath, const int& index) { return L""; }

		/// @fn AddFabric(const string& inputFilePath)
		/// @brief Add Fabric into the Object Browser
		/// @param inputFilePath: 'zfab'(clo file) path or 'jfab'(json) path
		/// @return the index of added fabric in object browser for the current project. .
		virtual unsigned int AddFabric(const string& inputFilePath) { return 0; }

		/// @fn AddFabricW(const wstring& inputFilePath)
		/// @brief Add Fabric into the Object Browser
		/// @param inputFilePath: 'zfab'(clo file) path or 'jfab'(json) path
		/// @return the index of added fabric in object browser for the current project. .
		virtual unsigned int AddFabricW(const wstring& inputFilePath) { return 0; }

		/// @fn GetFirstFabricTextureName()
		/// @brief Get the main image file name for the first fabric in the object browser for the current colorway index
		/// @return the name of the image file name without folder path and extension.
		virtual string GetFirstFabricTextureName() { return ""; }

		/// @fn GetFirstFabricTextureNameW()
		/// @brief Get the main image file name for the first fabric in the object browser for the current colorway index
		/// @return the name of the image file name without folder path and extension.
		virtual wstring GetFirstFabricTextureNameW() { return L""; }

		/// @fn GetFirstFabricTextureName(unsigned int colorwayIndex)
		/// @brief Get the main image file name for the first fabric in the object browser for a colorway index
		/// @param colorwayIndex: colorway index
		/// @return the name of the image file name without folder path and extension.
		virtual string GetFirstFabricTextureName(unsigned int colorwayIndex) { return ""; }

		/// @fn GetFirstFabricTextureNameW(unsigned int colorwayIndex)
		/// @brief Get the main image file name for the first fabric in the object browser for a colorway index
		/// @param colorwayIndex: colorway index
		/// @return the name of the image file name without folder path and extension.
		virtual wstring GetFirstFabricTextureNameW(unsigned int colorwayIndex) { return L""; }

		/// @fn ChangeFabricWithJson(unsigned int fabricIndex, const string& inputJsonFilePath)
		/// @brief Overwrite all the properties of a fabric with json file(.jfab) 
		/// @param fabricIndex: target fabric index in the object browser
		/// @param inputJsonFilePath: the jfab file path to load on to the fabric in the fabricIndex
		/// @return if it succeeds, return true.
		virtual bool ChangeFabricWithJson(unsigned int fabricIndex, const string& inputJsonFilePath) { return false; }

		/// @fn ChangeFabricWithJsonW(unsigned int fabricIndex, const wstring& inputJsonFilePath)
		/// @brief Overwrite all the properties of a fabric with json file(.jfab) 
		/// @param fabricIndex: target fabric index in the object browser
		/// @param inputJsonFilePath: the jfab file path to load on to the fabric in the fabricIndex
		/// @return if it succeeds, return true.
		virtual bool ChangeFabricWithJsonW(unsigned int fabricIndex, const wstring& inputJsonFilePath) { return false; }

		/// @fn AssignFabricToPattern(unsigned int fabricIndex, unsigned int patternIndex)
		/// @brief Assign a fabric to a pattern. 
		/// @param fabricIndex: the source fabric index in the object browser to apply to the target pattern
		/// @param patternIndex: the tagert pattern index to apply the fabric in the fabricIndex
		/// @return if it succeeds, return true.
		virtual bool AssignFabricToPattern(unsigned int fabricIndex, unsigned int patternIndex) { return false; }	

		/// @fn ImportXtexFile(unsigned int fabricIndex, const string& xTexFilePath)		
		/// @brief Import xtex to a fabric. Overwrite all the values described in the xtex file into the Fabric
		/// @parm fabricIndex: the target fabric index in the object browser to import xTex file onto
		/// @parm xTexFilePath: the xTex file path to import
		/// @return if it succeeds, return true.
		virtual bool ImportXtexFile(unsigned int fabricIndex, const string& xTexFilePath) { return false; }

		/// @fn ImportXtexFileW(unsigned int fabricIndex, const wstring& xTexFilePath)
		/// @brief Import xtex to a fabric. Overwrite all the values described in the xtex file into the Fabric
		/// @parm fabricIndex: the target fabric index in the object browser to import xTex file onto
		/// @parm xTexFilePath: the xTex file path to import
		/// @return if it succeeds, return true.
		virtual bool ImportXtexFileW(unsigned int fabricIndex, const wstring& xTexFilePath) { return false; }

		/// @fn ApplyXtexFile(unsigned int fabricIndex, const string& xTexFilePath)
		/// @brief Apply xtex to a fabric. Only set the values described in the xtex file into the Fabric.
		/// @parm fabricIndex: the target fabric index in the object browser to apply xTex file onto
		/// @parm xTexFilePath: the xTex file path to apply
		/// @return if it succeeds, return true.
		virtual bool ApplyXtexFile(unsigned int fabricIndex, const string& xTexFilePath) { return false; }

		/// @fn ApplyXtexFile(unsigned int fabricIndex, const string& xTexFilePath)
		/// @brief Apply xtex to a fabric. Only set the values described in the xtex file into the Fabric.
		/// @parm fabricIndex: the target fabric index in the object browser to apply xTex file onto
		/// @parm xTexFilePath: the xTex file path to apply
		/// @return if it succeeds, return true.
		virtual bool ApplyXtexFileW(unsigned int fabricIndex, const wstring& xTexFilePath) { return false; }
		
		/// @fn DeleteFabric(unsigned int fabricIndex)
		/// @brief Delete a fabric. If the fabric was assigned on Patterns, the patterns will have the default fabric
		/// @return if it succeeds, return true.
		virtual bool DeleteFabric(unsigned int fabricIndex) { return false; }

		/// @fn GetAPIMetaData(unsigned int fabricIndex)
		/// @brief Get API meta data for the fabric
		/// @parm fabricIndex: target fabric index on the Object Browser
		/// @return json string for meta data [key - value] list
		virtual string GetAPIMetaData(unsigned int fabricIndex) { return "";		}

		/// @fn GetAPIMetaDataW(unsigned int fabricIndex)
		/// @brief Get API meta data for the fabric
		/// @parm fabricIndex: target fabric index on the Object Browser
		/// @return json string for meta data [key - value] list
		virtual wstring GetAPIMetaDataW(unsigned int fabricIndex) { return L""; }

		/// @fn SetAPIMetaData(unsigned int fabricIndex, string jsonStr)
		/// @brief Set API meta data for the fabric
		/// @param fabricIndex: target fabric index on the Object Browser
		/// @param jsonStr: api meta data in string format 
		/// @return if it succeeds, return true
		virtual bool SetAPIMetaData(unsigned int fabricIndex, string jsonStr) { return ""; }

		/// @fn SetAPIMetaData(unsigned int fabricIndex, string jsonStr)
		/// @brief Set API meta data for the fabric
		/// @param fabricIndex: target fabric index on the Object Browser
		/// @param jsonStr: api meta data in string format 
		/// @return if it succeeds, return true
		virtual bool SetAPIMetaDataW(unsigned int fabricIndex, wstring jsonStr) { return L""; }

		/// @fn ChangeMetaDataValueForFabric(unsigned int fabricIndex, const string& metaDataKey, const string& metaDataValue)
		/// @brief Change or add Meta Data Value for the fabric with the index
		/// @param fabricIndex: target Fabric 
		/// @param metaDataKey: target Key
		/// @param metaDataValue: the new value for the key
		virtual void ChangeMetaDataValueForFabric(unsigned int fabricIndex, const string& metaDataKey, const string& metaDataValue) {}

		/// @fn ChangeMetaDataValueForFabric(unsigned int fabricIndex, const wstring& metaDataKey, const wstring& metaDataValue)
		/// @brief Change or add Meta Data Value for the fabric with the index
		/// @param fabricIndex: target Fabric 
		/// @param metaDataKey: target Key
		/// @param metaDataValue: the new value for the key
		virtual void ChangeMetaDataValueForFabric(unsigned int fabricIndex, const wstring& metaDataKey, const wstring& metaDataValue) {}

		/// @fn GetFabricSize()
		/// @brief Get the number of fabrics on the Object Browser
		/// @return return the number of fabrics on the object browser
		virtual int GetFabricSize() { return 0; } // deprecated. please use 'GetFabricCount()' function

		/// @fn GetFabricIndexForPattern(int patternIndex)
		/// @brief Get the fabric index which is assigned on the pattern with the pattern index
		/// @param patternIndex: the input pattern index to get the fabric index
		/// @return fabric index on the object browser for the pattern with the pattern index
		virtual int GetFabricIndexForPattern(int patternIndex) { return 0; }

		/// @fn GetFabricIndex(const string& fabricName)
		/// @brief Get the fabric index which is using the fabric name
		/// @param fabricName: the fabric name to get the fabric index
		/// @return fabric index
		virtual int GetFabricIndex(const string& fabricName) { return 0; }

		/// @fn GetFabricIndexW(const wstring& fabricName)
		/// @brief Get the fabric index which is using the fabric name
		/// @param fabricName: the fabric name to get the fabric index
		/// @return fabric index
		virtual int GetFabricIndexW(const wstring& fabricName) { return 0; }

		/// @fn GetFabricName(int fabricIndex)
		/// @brief Get the fabric name of the fabric in the fabricIndex on the object browser
		/// @parm fabricIndex: the fabric index to get the name
		/// @return fabric name
		virtual string GetFabricName(int fabricIndex) { return ""; }

		/// @fn GetFabricNameW(int fabricIndex)
		/// @brief Get the fabric name of the fabric in the fabricIndex on the object browser
		/// @parm fabricIndex: the fabric index to get the name
		/// @return fabric name
		virtual wstring GetFabricNameW(int fabricIndex) { return L""; }

		/// @fn GetColorwayFabricInfo(int colorwayIndex, int fabricIndex)
		/// @brief Get a fabric information for a colorway
		/// @param colorwayIndex: the colorway index for the fabric to get the fabric info
		/// @param fabricIndex: the fabricIndex for the fabric to get the fabric info
		/// @return json string for fabric information
		virtual string GetColorwayFabricInfo(int colorwayIndex, int fabricIndex) { return ""; }

		/// @fn GetColorwayFabricInfoW(int colorwayIndex, int fabricIndex)
		/// @brief Get a fabric information for a colorway
		/// @param colorwayIndex: the colorway index for the fabric to get the fabric info
		/// @param fabricIndex: the fabricIndex for the fabric to get the fabric info
		/// @return json string for fabric information
		virtual wstring GetColorwayFabricInfoW(int colorwayIndex, int fabricIndex) { return L""; }

		/// @fn GetAPIMetaDataFromFile(const string& filePath)
		/// @brief Get API meta data for the fabric
		/// @param filePath: filepath (.zfab / .jfab)
		/// @return json string for meta data [key - value] list
		virtual string GetAPIMetaDataFromFile(const string& filePath) { return ""; }

		/// @fn GetAPIMetaDataFromFileW(const wstring& filePath)
		/// @brief Get API meta data for the fabric
		/// @param filePath: filepath (.zfab / .jfab)
		/// @return json string for meta data [key - value] list
		virtual wstring GetAPIMetaDataFromFileW(const wstring& filePath) { return L""; }
	};
}
