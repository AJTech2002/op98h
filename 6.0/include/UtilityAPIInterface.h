#pragma once

#include <vector>
#include <map>

#include "DefineDllForWin.h"
#include "CloApiData.h"


namespace CLOAPI
{
    using namespace std;

	class MV_CLO_INTERFACE_API UtilityAPIInterface {
	public:
		/// @fn GetCLOTemporaryFolderPath()
		/// @brief Create and get the temporary folder path
		/// @return Get the temporary folder path to store temporary files used when exporting to server
		virtual string GetCLOTemporaryFolderPath() { return ""; }

		/// @fn GetCLOTemporaryFolderPathW()
		/// @brief Create and get the temporary folder path
		/// @return Get the temporary folder path to store temporary files used when exporting to server
		virtual wstring GetCLOTemporaryFolderPathW() { return L""; }

		/// @fn DisplayMessageBox(string str)
		/// @brief Show a message with using the DialogBox implemented in CLO software
		/// @param str: message
		/// @return Display a message box to show input string on CLO. This can be used for debugging.
		virtual void DisplayMessageBox(string str) {}

		/// @fn DisplayMessageBoxW(wstring str)
		/// @brief Show a message with using the DialogBox implemented in CLO software
		/// @param str: message
		/// @return Display a message box to show input string on CLO. This can be used for debugging.
		virtual void DisplayMessageBoxW(wstring str) {}

		/// @fn GetProjectName()
		/// @brief Get the current project name in CLO
		/// @return The current project name. When you opening "test.zprj" file at last, then the project name is given as "test"
		virtual string GetProjectName() { return ""; }

		/// @fn GetProjectNameW()
		/// @brief Get the current project name in CLO
		/// @return The current project name. When you opening "test.zprj" file at last, then the project name is given as "test"
		virtual wstring GetProjectNameW() { return L""; }

		/// @fn GetProjectFilePath()
		/// @brief Get the current profile file path
		/// @return The current project file path. If you load a project file saved in "c://download/default.zprj", this function returns the full path - "c://download/default.zprj". If you never load project files, then it returns "NULL".
		virtual string GetProjectFilePath() { return ""; }

		/// @fn GetProjectFilePathW()
		/// @brief Get the current profile file path
		/// @return The current project file path. If you load a project file saved in "c://download/default.zprj", this function returns the full path - "c://download/default.zprj". If you never load project files, then it returns "NULL".
		virtual wstring GetProjectFilePathW() { return L""; }

		/// @fn GetMajorVersion()
		/// @brief Get the major version of the CLO software
		/// @return Major version of SW. ex) 5 of 5.0.72
		virtual unsigned int GetMajorVersion() { return 0; }

		/// @fn GetMinorVersion()
		/// @brief Get the minor version of the CLO software
		/// @return Minor version of SW. ex) 0 of 5.0.72
		virtual unsigned int GetMinorVersion() { return 0; }

		/// @fn GetPatchVersion()
		/// @brief Get the patch version of the CLO software
		/// @return Patch version of SW. ex) 72 of 5.0.72
		virtual unsigned int GetPatchVersion() { return 0; }

		/// @fn toUtf8(const std::wstring &str)
		/// @brief Convert and get the string encoded in UTF-8 from wstring
		/// @param str: target wstring to convert
		/// @return string in UTF8 from wstring encoded by UCS-2 in Windows or UTF-8 in Mac OS
		virtual std::string toUtf8(const std::wstring &str) { return ""; }

		/// @fn GetColorwayCount()
		/// @brief Get the number of colorways in the current project
		/// @return The number of Colorways in the current project.
		virtual unsigned int GetColorwayCount() { return 0; }

		/// @fn GetCurrentColorwayIndex()
		/// @brief Get the current colorway index
		/// @return The current colorway index.
		virtual unsigned int GetCurrentColorwayIndex() { return 0; }

		/// @fn SetCurrentColorwayIndex(unsigned int index)
		/// @brief Change the current colorway
		/// @param index: the colorway index
		virtual void SetCurrentColorwayIndex(unsigned int index) { }

		/// @fn SetColorwayName(unsigned int index, const string& str)
		/// @brief Change colorway name
		/// @param index: the target colorway index to change the name
		/// @param str: new name for the colorway
		virtual void SetColorwayName(unsigned int index, const string& str) {}

		/// @fn SetColorwayNameW(unsigned int index, const wstring& wstr)
		/// @brief Change colorway name
		/// @param index: the target colorway index to change the name
		/// @param str: new name for the colorway
		virtual void SetColorwayNameW(unsigned int index, const wstring& wstr) {}

		/// @fn GetColorwayName(unsigned int index)
		/// @brief Get the colorway name for the colorway index
		/// @param index: colorway index to get the name
		/// @return the colorway name for the colorway index
		virtual string GetColorwayName(unsigned int index) { return ""; }

		/// @fn GetColorwayNameW(unsigned int index)
		/// @brief Get the colorway name for the colorway index
		/// @param index: colorway index to get the name
		/// @return the colorway name for the colorway index
		virtual wstring GetColorwayNameW(unsigned int index) { return L""; }

		/// @fn CopyColorway(unsigned int index)
		/// @brief Copy the colorway in the index and create a new one
		/// @param index: the source colorway index to copy
		/// @return index for the created colorway
		virtual unsigned int CopyColorway(unsigned int index) { return 0; }

		/// @fn RefreshColorwayDialog(bool bCheckIfColorwayMode = true)	
		/// @brief Refresh Colorway Dialog in the CLO software
		/// @param bCheckIfColorwayMode: put the value to true to refresh the colorway dialog when the CLO software is on the colorway mode
		virtual void RefreshColorwayDialog(bool bCheckIfColorwayMode = true) {}

		/// @fn GetCustomViewInformation()
		/// @brief Get the custom view information		
		/// {
		/// "customViewList": [
		/// 	{
		/// 		"cameraMatrix": [ // row vector 0, 1, 2 of "local to world camera matrix"
		/// 		  1.0,
		/// 		  0.000166,
		/// 		  -0.001024,
		/// 		  0.352125,
		/// 		  0.0,
		/// 		  0.987069,
		/// 		  0.160306,
		/// 		  2592.8,
		/// 		  0.001039,
		/// 		  -0.160306,
		/// 		  0.987068,
		/// 		  7973.05
		/// 		],
		/// 		"fov": 40.0
		/// 	}
		/// ]
		/// }		
		/// @return Json stream including the data of Custom View such as Camera Matrix, FOV, and so on.
		virtual string GetCustomViewInformation() { return ""; }

		/// @fn GetCustomViewInformationW()
		/// @brief Get the custom view information		
		/// {
		/// "customViewList": [
		/// 	{
		/// 		"cameraMatrix": [ // row vector 0, 1, 2 of "local to world camera matrix"
		/// 		  1.0,
		/// 		  0.000166,
		/// 		  -0.001024,
		/// 		  0.352125,
		/// 		  0.0,
		/// 		  0.987069,
		/// 		  0.160306,
		/// 		  2592.8,
		/// 		  0.001039,
		/// 		  -0.160306,
		/// 		  0.987068,
		/// 		  7973.05
		/// 		],
		/// 		"fov": 40.0
		/// 	}
		/// ]
		/// }		
		/// @return Json stream including the data of Custom View such as Camera Matrix, FOV, and so on.
		virtual wstring GetCustomViewInformationW() { return L""; }

		/*
		Simulate the cloth in a step. All dynamics properties (time step, CG iteration count, ...) follows the current simulation properties
		*/
		//virtual void SimulateOneStep() {}

		/// @fn GetClothPositions(vector<float>& positions)
		/// @brief Get the position array of cloth shape. Each three array has x, y, z position of each vertex. 
		/// @param positions: the output position list for the cloth shape
		virtual void GetClothPositions(vector<float>& positions) {}

		/// @fn ResetClothArrangement()
		/// @brief Restore the shape of cloth to when the cloth was loaded
		virtual void ResetClothArrangement() {}

		/// @fn GetThumbnailInCLOFile(std::string filePath, unsigned int thumbnailIndex, unsigned int& fileSize)
		/// @brief Get Preview thumbnail file buffer(png type) from the CLO file format(.zprj, .zpac, .zfab, .sst, and so on)
		/// @param filePath: the source file path to retrieve the thumbnail buffer
		/// @param thumbnailIndex: the index of the thumbnails in the CLO file format(the number of thumbnails differs by the format)
		/// @param fileSize: get the size of the thumbnail buffer
		/// @return thumbnail(png) buffer
		virtual unsigned char* GetThumbnailInCLOFile(std::string filePath, unsigned int thumbnailIndex, unsigned int& fileSize) { return nullptr; }

		/// @fn GetAssetIconInCLOFile(std::string filePath, unsigned int& fileSize)
		/// @brief Get Asset Icon thumbnail file buffer(png type) from the CLO file format(.zprj, .zpac, .zfab, .sst, and so on)
		/// @param filePath: the source file path to retrieve the thumbnail buffer		
		/// @param fileSize: get the size of the thumbnail buffer
		/// @return thumbnail(png) buffer
		virtual unsigned char* GetAssetIconInCLOFile(std::string filePath, unsigned int& fileSize) { return nullptr; }

		/// @fn GetMetaDataForCurrentGarment()
		/// @brief Get Meta data for the current Garment
		/// @return the meta data for the current garment
		virtual string GetMetaDataForCurrentGarment() { return ""; }

		/// @fn GetMetaDataForCurrentGarmentW()
		/// @brief Get Meta data for the current Garment
		/// @return the meta data for the current garment
		virtual wstring GetMetaDataForCurrentGarmentW() { return L""; }

		/// @fn SetMetaDataForCurrentGarment(const string& metaDataStr)
		/// @brief Overwrite Meta data for the current Garment
		/// @param metaDataStr: the new meata data to set to the current garment
		virtual void SetMetaDataForCurrentGarment(const string& metaDataStr) { return; }

		/// @fn ChangeMetaDataValueForCurrentGarment(const string& metaDataKey, const string& metaDataValue)
		/// @brief Change Meta Data Value for the current Garment
		/// @metaDataKey: target Key
		/// @metaDataValue: the new value for the key
		virtual void ChangeMetaDataValueForCurrentGarment(const string& metaDataKey, const string& metaDataValue) {}

		/// @fn CreateProgressBar()
		/// @brief Create Progress Bar to show progress. This function should be called before using SetProgress function		
		virtual void CreateProgressBar() {}

		/// @fn SetProgress(const string& title, int progress)
		/// @brief Set progress on the Progress Bar
		virtual void SetProgress(const string& title, int progress) {}

		/// @fn SetProgress(const string& title, int progress)
		/// @brief Set progress on the Progress Bar
		virtual void SetProgressW(const wstring& title, int progress) {}

		/// @fn DeleteProgressBar(bool bForce)
		/// @brief Delete the current Progress Bar. This function should be called after using the SetProgress funtion
		/// @param bForce: true - retry to delete progress bar; false - try only once to delete progress bar
		virtual void DeleteProgressBar(bool bForce) {}

		/// @fn stringToMD5(const string& str)
		/// @brief Create MD5 hashing string from string
		/// @param str: the source string to hash 
		/// @return MD5 hashed string
		virtual string stringToMD5(const string& str) { return ""; }

		/// @fn AddColorSwatch(const map<string, string>& plmIDtoNameList, const map<string, Marvelous::CloApiRgb>& plmIDtoColorList, const map<string, string>& plmIDtoApiMetaDataList, const string& swatchName)
		/// @brief Add Color Swatch
		/// @param plmIDtoNameList: the list for map of PLM ID to Color Name
		/// @param plmIDtoColorList: list for map of PLM ID to color name
		/// @param plmIDtoApiMetaDataList: list for map of PLM ID to Api Meta Data
		/// @param swatchName: swatchName which will be shown in the color palette and the swatch file name to save
		/// @return added swatch file name(.aco) inside the asset folder for the current version of CLO
		virtual string AddColorSwatch(const map<string, string>& plmIDtoNameList, const map<string, Marvelous::CloApiRgb>& plmIDtoColorList, const map<string, string>& plmIDtoApiMetaDataList, const string& swatchName) { return ""; }

		/// @fn AddColorSwatchW(const map<wstring, wstring>& plmIDtoNameList, const map<wstring, Marvelous::CloApiRgb>& plmIDtoColorList, const map<wstring, wstring>& plmIDtoApiMetaDataList, const wstring& swatchName)
		/// @brief Add Color Swatch
		/// @param plmIDtoNameList: the list for map of PLM ID to Color Name
		/// @param plmIDtoColorList: list for map of PLM ID to color name
		/// @param plmIDtoApiMetaDataList: list for map of PLM ID to Api Meta Data
		/// @param swatchName: swatchName which will be shown in the color palette and the swatch file name to save
		/// @return added swatch file name(.aco) inside the asset folder for the current version of CLO
		virtual wstring AddColorSwatchW(const map<wstring, wstring>& plmIDtoNameList, const map<wstring, Marvelous::CloApiRgb>& plmIDtoColorList, const map<wstring, wstring>& plmIDtoApiMetaDataList, const wstring& swatchName) { return L""; }
		
		/// @fn NewProject()
		/// @brief Clear the current garment and begin a new garment
		virtual void NewProject() {}
		
		/// API calls; especially for Library Windows Sample Demo.
		/// - IsReadableImageFormatFromExtension / IsReadableImageFormatFromExtensionW
		/// : Check if the file stream loaded from the filepath used in Library Windows Implementations can be displayed on Library Windows for item thumbnail and/or preview dialog.
		///   (The files should not contain image data over 8bits per channel for 1 ~ 4 channels image.)
		/// - IsCLOFileFormatWithThumbnailExtension / IsCLOFileFormatWithThumbnailExtensionW
		/// : Check if the CLO file format has the thumbnail memory.
		/// 			
		/// - IsCLOFileFormatWithTripleThumbnailExtension / IsCLOFileFormatWithTripleThumbnailExtensionW
		/// : Check if the CLO file format has the three images memory for preview thumbnail for the Library Preview Dialog.

		/// @fn IsReadableImageFormat(const string& filePath)
		/// @brief Check if the file stream loaded from the filepath used in Library Windows Implementations can be displayed on Library Windows for item thumbnail and/or preview dialog.
		/// @return true if the file can be displayed on Library Windows for item thumbnail and/or preview dialog
		virtual bool IsReadableImageFormat(const string& filePath) { return false; }

		/// @fn IsReadableImageFormatW(const wstring& filePath)
		/// @brief Check if the file stream loaded from the filepath used in Library Windows Implementations can be displayed on Library Windows for item thumbnail and/or preview dialog.
		/// @return true if the file can be displayed on Library Windows for item thumbnail and/or preview dialog
		virtual bool IsReadableImageFormatW(const wstring& filePath) { return false; }

		/// @fn IsCLOFileFormatWithThumbnail(const string& filePath)
		/// @brief Check if the CLO file format has the thumbnail memory.
		/// @return true if the file is the CLO format file and contains the thumbnail memory which can be displayed on Library Windows for item thumbnail and/or preview dialog
		virtual bool IsCLOFileFormatWithThumbnail(const string& filePath) { return false; }

		/// @fn IsCLOFileFormatWithThumbnailW(const wstring& filePath)
		/// @brief Check if the CLO file format has the thumbnail memory.
		/// @return true if the file is the CLO format file and contains the thumbnail memory which can be displayed on Library Windows for item thumbnail and/or preview dialog
		virtual bool IsCLOFileFormatWithThumbnailW(const wstring& filePath) { return false; }
		
		/// @fn IsCLOFileFormatWithTripleThumbnail(const string& filePath)
		/// @brief Check if the CLO file format has the three images memory for preview thumbnail for the Library Preview Dialog.
		/// @return true if the CLO file format has the three images memory for preview thumbnail for the Library Preview Dialog.
		virtual bool IsCLOFileFormatWithTripleThumbnail(const string& filePath) { return false; }

		/// @fn IsCLOFileFormatWithTripleThumbnailW(const wstring& filePath)
		/// @brief Check if the CLO file format has the three images memory for preview thumbnail for the Library Preview Dialog.
		/// @return true if the CLO file format has the three images memory for preview thumbnail for the Library Preview Dialog.
		virtual bool IsCLOFileFormatWithTripleThumbnailW(const wstring& filePath) { return false; }

		/// @fn GetCLOExecutableFolderPath(bool bLinuxTypePathDelimeter = true)
		/// @brief Get the executable folder path where the current version of CLO is located
		/// @param bLinuxTypePathDelimeter: if true, set path delimiter to '/', false: set path delimiter to '\'
		/// @return Get the executable folder path for the current version of CLO software
		virtual string GetCLOExecutableFolderPath(bool bLinuxTypePathDelimeter = true) { return ""; }

		/// @fn GetCLOExecutableFolderPathW(bool bLinuxTypePathDelimeter = true)
		/// @brief Get the executable folder path where the current version of CLO is located
		/// @param bLinuxTypePathDelimeter: if true, set path delimiter to '/', false: set path delimiter to '\'
		/// @return Get the executable folder path for the current version of CLO software
		virtual wstring GetCLOExecutableFolderPathW(bool bLinuxTypePathDelimeter = true) { return L""; }

		/// @fn GetCLOAssetFolderPath(bool bLinuxTypePathDelimeter = true)
		/// @brief Get the folder path where the CLO asset files are distributed
		/// @param bLinuxTypePathDelimeter: if true, set path delimiter to '/', false: set path delimiter to '\'
		/// @return Get the asset folder path where the CLO asset files are located in
		virtual string GetCLOAssetFolderPath(bool bLinuxTypePathDelimeter = true) { return ""; }

		/// @fn GetCLOAssetFolderPathW(bool bLinuxTypePathDelimeter = true)
		/// @brief Get the folder path where the CLO asset files are distributed
		/// @param bLinuxTypePathDelimeter: if true, set path delimiter to '/', false: set path delimiter to '\'
		/// @return Get the asset folder path where the CLO asset files are located in
		virtual wstring GetCLOAssetFolderPathW(bool bLinuxTypePathDelimeter = true) { return L""; }

		/// @fn GetAPIMetaData(const string& filePath)
		/// @brief Get API meta data for the file
		/// @param filePath: CLO file path
		/// @return json string for meta data [key - value] list		
		virtual string GetAPIMetaData(const string& filePath) { return ""; }

		/// @fn GetAPIMetaDataW(const wstring& filePath)
		/// @brief Get API meta data for the file
		/// @param filePath: CLO file path
		/// @return json string for meta data [key - value] list
		virtual wstring GetAPIMetaDataW(const wstring& filePath) { return L""; }

		/// @fn SetAPIMetaData(const string& filePath, string jsonStr)
		/// @brief Set API meta data to the file
		/// @param filePath: target file path
		/// @param jsonStr: api meta data in string format
		/// @return if it succeeds, return true
		virtual bool SetAPIMetaData(const string& filePath, string jsonStr) { return ""; }

		/// @fn SetAPIMetaDataW(const wstring& filePath, wstring jsonStr)
		/// @brief Set API meta data to the file
		/// @param filePath: target file path
		/// @param jsonStr: api meta data in string format
		/// @return if it succeeds, return true
		virtual bool SetAPIMetaDataW(const wstring& filePath, wstring jsonStr) { return L""; }

		/// @fn Set3DWindowTitle(const string& title)
		/// @brief Set 3D Window Title
		/// @param title: desired text in 3D window
		/// @return if it succeeds, return true
		virtual bool Set3DWindowTitle(const string& title) { return false; }

		/// @fn Set3DWindowTitleW(const wstring& title) 
		/// @brief Set 3D Window Title
		/// @param title: desired text in 3D window
		/// @return if it succeeds, return true
		virtual bool Set3DWindowTitleW(const wstring& title) { return false; }
	};
}
