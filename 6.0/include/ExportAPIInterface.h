#pragma once


#include <vector>

#include "DefineDllForWin.h"

#include "CloApiData.h"

#if defined(__APPLE__)
#include <string>
#endif

namespace CLOAPI
{
using namespace std;

	class MV_CLO_INTERFACE_API ExportAPIInterface {
	public:

		/// @fn ExportZPac()
		/// @brief Export ZPac file in the CLO temporary folder
		/// @return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual string ExportZPac() { return ""; }

		/// @fn ExportZPac(const string& _filePath)
		/// @brief Export ZPac file
		/// @param string _filePath : target file path in ASCII
		/// @return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual string ExportZPac(const string& _filePath) { return ""; }

		/// @fn ExportZPacW(const wstring& _filePath)
		/// @brief Export ZPac file
		/// @param wstring _filePath : target file path in UNICODE
		/// @return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual wstring ExportZPacW(const wstring& _filePath) { return L""; }
		
		/// @fn ExportZPrj()
		/// @brief Export ZPrj file 
		/// @return Output file path; output files will be created in CLO temporary folder.
		virtual string ExportZPrj() { return ""; }

		/// @fn ExportZPrj(const string& _filePath)
		/// @brief Export ZPrj file 
		/// @param _filePath: output file path
		/// @return Output file path. If an error occurs, return empty string.
		virtual string ExportZPrj(const string& _filePath) { return ""; }

		/// @fn ExportZPrj(const string& _filePath, bool _bCreateThumbnail)
		/// @brief Export ZPrj file 
		/// @param _filePath: output file path
		/// @param _bCreateThumbnail: if _bCreateThumbnail is true, 'png' file will be created along 'zprj' file.
		/// @return Output file path. If an error occurs, return empty string.
		virtual string ExportZPrj(const string& _filePath, bool _bCreateThumbnail) { return ""; }

		/// @fn ExportZPrjW(const wstring& _filePath, bool _bCreateThumbnail)
		/// @brief Export ZPrj file 
		/// @param _filePath: output file path
		/// @param _bCreateThumbnail: if _bCreateThumbnail is true, 'png' file will be created along 'zprj' file.
		/// @return Output file path. If an error occurs, return empty wstring.
		virtual wstring ExportZPrjW(const wstring& _filePath, bool _bCreateThumbnail) { return L""; }
		
		///	@fn ExportOBJ()
		/// @brief Export OBJ file
		/// @param options If "options" is given, it exports OBJ according to options, not allowing user for selecting options in Export Dialog.
		/// @return Output file paths. It outputs the file paths of an OBJ file and multiple MTL files for colorways. If the value "bSaveInZip" in ImportExportOption is true, it outputs a file path of a zipped file. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual vector<string> ExportOBJ()
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		///	@fn ExportOBJ()
		/// @brief Export OBJ file
		/// @param _filePath: output file path
		/// @return Output file paths. It outputs the file paths of an OBJ file and multiple MTL files for colorways. If the value "bSaveInZip" in ImportExportOption is true, it outputs a file path of a zipped file. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual vector<string> ExportOBJ(const string& _filePath)
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		///	@fn ExportOBJ(const Marvelous::ImportExportOption& _options)
		/// @brief Export OBJ file
		/// @param options: If "options" is given, it exports OBJ according to options, not allowing user for selecting options in Export Dialog.
		/// @return Output file paths. It outputs the file paths of an OBJ file and multiple MTL files for colorways. If the value "bSaveInZip" in ImportExportOption is true, it outputs a file path of a zipped file. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual vector<string> ExportOBJ(const Marvelous::ImportExportOption& _options)
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		///	@fn ExportOBJ(const string& _filePath, const Marvelous::ImportExportOption& _options)
		/// @brief Export OBJ file
		/// @param _filePath: output file path
		/// @param options: If "options" is given, it exports OBJ according to options, not allowing user for selecting options in Export Dialog.
		/// @return Output file paths. It outputs the file paths of an OBJ file and multiple MTL files for colorways. If the value "bSaveInZip" in ImportExportOption is true, it outputs a file path of a zipped file. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual vector<string> ExportOBJ(const string& _filePath, const Marvelous::ImportExportOption& _options)
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		///	@fn ExportOBJW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		/// @brief Export OBJ file
		/// @param _filePath: output file path
		/// @param options: If "options" is given, it exports OBJ according to options, not allowing user for selecting options in Export Dialog.
		/// @return Output file paths. It outputs the file paths of an OBJ file and multiple MTL files for colorways. If the value "bSaveInZip" in ImportExportOption is true, it outputs a file path of a zipped file. If an error occurs, return empty wstring. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual vector<wstring> ExportOBJW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		{
			vector<wstring> interface_vector;
			return interface_vector;
		}
		
		/// @fn ExportGLTF(const string& _filePath, const Marvelous::ImportExportOption& _options)
		///	@brief Export GLTF
		///	@param options: If "options" is given, it exports GLTF according to options, not allowing user for selecting options in Export Dialog.
		///	@return Output file paths. 
		virtual vector<string> ExportGLTF(const string& _filePath, const Marvelous::ImportExportOption& _options, bool _bGLBinary)
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		/// @fn ExportGLTFW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		///	@brief Export GLTFW
		///	@param options: If "options" is given, it exports GLTF according to options, not allowing user for selecting options in Export Dialog.
		///	@return Output file paths. 
		virtual vector<wstring> ExportGLTFW(const wstring& _filePath, const Marvelous::ImportExportOption& _options, bool _bGLBinary)
		{
			vector<wstring> interface_vector;
			return interface_vector;
		}
				
		/// @fn ExportDXF()
		/// @brief Export DXF file. This api call will display the dialog to set options
		/// @return Output file path. If an error occurs, return empty string. Output files will be created in CLO temporary folder.
		virtual string ExportDXF() { return ""; }

		/// @fn ExportDXF(const string& _filePath)
		/// @brief Export DXF file. This api call will display the dialog to set options
		/// @param _filePath: output file path to export dxf
		/// @return Output file path. If an error occurs, return empty string. 
		virtual string ExportDXF(const string& _filePath) { return ""; }

		/// @fn ExportDXF(const string& _filePath, const Marvelous::ExportDxfOption& _exportOption)
		/// @brief Export DXF file without the option dialog. Param ExportDxfOption is applicable for the options.
		/// @param _filePath: output file path to export dxf
		/// @param _exportOption: options to export dxf file
		/// @return Output file path. If an error occurs, return empty string. 
		virtual string ExportDXF(const string& _filePath, const Marvelous::ExportDxfOption& _exportOption) { return ""; } // without dialog

		/// @fn ExportDXF(const string& _filePath, const Marvelous::ExportDxfOption& _exportOption)
		/// @brief Export DXF file without the option dialog. Param ExportDxfOption is applicable for the options.
		/// @param _filePath: output file path
		/// @param _exportOption: options to export dxf file
		/// @return Output file path. If an error occurs, return empty wstring. 
		virtual wstring ExportDXFW(const wstring& _filePath, const Marvelous::ExportDxfOption& _exportOption) { return L""; } // without dialog

		/// @fn ExportTechPack(const string& _filePath, const Marvelous::ExportTechpackOption& _exportOption)
		/// @brief Export Tech Pack data in json file and associated image files.
		/// @param _filePath: output filepath; the filePath Should be given in "*.json" format
		/// @param _exportOption: options to export techpack(.json) file
		virtual void ExportTechPack(const string& _filePath, const Marvelous::ExportTechpackOption& _exportOption) {}

		/// @fn ExportTechPackW(const wstring& _filepath, const Marvelous::ExportTechpackOption& _exportOption)
		/// @brief Export Tech Pack data in json file and associated image files.
		/// @param _filePath: output filepath; the filePath Should be given in "*.json" format
		/// @param _exportOption: options to export techpack(.json) file
		virtual void ExportTechPackW(const wstring& _filepath, const Marvelous::ExportTechpackOption& _exportOption) {}

		/// @fn ExportTechPackToStream(string& _outputImageFolderPath)
		/// @brief Export Tech Pack data in string and associated image files.
		/// @param _outputImageFolderPath: get output folder path where the image files are located by ExportTechpack
		/// @return Output stream for JSON data with the output folder path at the first line. If an error occurs, return empty string.
		virtual string ExportTechPackToStream(string& _outputImageFolderPath) { _outputImageFolderPath = "";  return ""; }

		/// @fn ExportTechPackToStreamW(wstring& _outputImageFolderPath)
		/// @brief Export Tech Pack data in string and associated image files.
		/// @param _outputImageFolderPath: get output folder path where the image files are located by ExportTechpack
		/// @return Output stream for JSON data with the output folder path at the first line. If an error occurs, return empty wstring.
		virtual wstring ExportTechPackToStreamW(wstring& _outputImageFolderPath) { _outputImageFolderPath = L"";  return L""; }

		/// @fn ExportThumbnail3D()
		/// @brief Export thumbnail of the current scene
		/// @return Output file path: output files will be created in CLO temporary folder.
		virtual string ExportThumbnail3D() { return ""; }
		
		/// @fn ExportThumbnail3D(const string& _filePath)
		/// @brief Export thumbnail of the current scene in the 3D Windows
		/// @param _filePath: output file path to save the screenshot
		/// @return Output file path. If an error occurs, return empty string. 
		virtual string ExportThumbnail3D(const string& _filePath) { return ""; }

		/// @fn ExportThumbnail3D(const string& _filePath)
		/// @brief Export thumbnail of the current scene in the 3D Windows
		/// @param _filePath: output file path to save the screenshot
		/// @return Output file path. If an error occurs, return empty wstring. 
		virtual wstring ExportThumbnail3DW(const wstring& _filePath) { return L""; }
		
		/// @fn ExportSnapshot3D(const string& _filePath)
		/// @brief Export snapshot images. This function displays the same dialog as CLO so that users can configure the snapshots. If user turns on the option "Save Separate Images", then series of images will be saved with the name followed by the postfix "_01", "_02", ...
		/// @param _filePath: output file path to save the screenshot
		/// @return Return the list of the path of output files per colorway. The first item of each array is the file path of the unified image. If filePath parameter is not given, output files will be created in CLO temporary folder.	
		virtual vector< vector < string > > ExportSnapshot3D(const string& _filePath)
		{
			vector< vector < string > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportSnapshot3D()
		/// @brief Export snapshot images. This function displays the same dialog as CLO so that users can configure the snapshots. If user turns on the option "Save Separate Images", then series of images will be saved with the name followed by the postfix "_01", "_02", ...		
		/// @return Return the list of the path of output files per colorway. The first item of each array is the file path of the unified image. If filePath parameter is not given, output files will be created in CLO temporary folder.	
		virtual vector< vector < string > > ExportSnapshot3D()
		{
			vector< vector < string > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportSnapshot3DW(const wstring& _filePath)
		/// @brief Export snapshot images. This function displays the same dialog as CLO so that users can configure the snapshots. If user turns on the option "Save Separate Images", then series of images will be saved with the name followed by the postfix "_01", "_02", ...
		/// @param _filePath: output file path to save the screenshot
		/// @return Return the list of the path of output files per colorway. The first item of each array is the file path of the unified image. If filePath parameter is not given, output files will be created in CLO temporary folder.	
		virtual vector< vector < wstring > > ExportSnapshot3DW(const wstring& _filePath)
		{
			vector< vector < wstring > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportCustomViewSnapshot(const string& _targetFolderPath, unsigned int _width, unsigned int _height, string _outputPrefix = "")
		/// @brief Export snapshot images of Custom View.
		/// @param _targetFolderPath: output folder path
		/// @param _width: image width for the snapshots
		/// @param _height: image height for the snapshots
		/// @param _outputPrefix: If you set the 'outputPrefix' as empty value - "", then the saved file names will start with the index in the custom view; or if you set the 'outputPrefix' as some letters, the saved file names will have it as the first letters.
		/// @return Return the list of the path of output files
		virtual vector < string > ExportCustomViewSnapshot(const string& _targetFolderPath, unsigned int _width, unsigned int _height, string _outputPrefix = "")
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		/// @fn ExportCustomViewSnapshotW(const wstring& _targetFolderPath, unsigned int _width, unsigned int _height, wstring _outputPrefix = L"")
		/// @brief Export snapshot images of Custom View.
		/// @param _targetFolderPath: output folder path
		/// @param _width: image width for the snapshots
		/// @param _height: image height for the snapshots
		/// @param _outputPrefix: If you set the 'outputPrefix' as empty value - "", then the saved file names will start with the index in the custom view; or if you set the 'outputPrefix' as some letters, the saved file names will have it as the first letters.
		/// @return Return the list of the path of output files
		virtual vector < wstring > ExportCustomViewSnapshotW(const wstring& _targetFolderPath, unsigned int _width, unsigned int _height, wstring _outputPrefix = L"")
		{
			vector<wstring> interface_vector;
			return interface_vector;
		}

		/// @fn ExportRenderingImage(const string& _filePath)
		/// @brief Export Rendering Image.
		/// @param _filePath: output file path
		/// @return Return the list of the path of output files per colorway. 
		virtual vector< vector < string > > ExportRenderingImage(const string& _filePath)
		{
			vector< vector < string > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportRenderingImage(const string& _filePath, bool _bRenderAllColorways)
		/// @brief Export Rendering Image.
		/// @param _filePath: output file path
		/// @param _bRenderAllColorways: If true, output the images for all colorways. Otherwise, it returns the images for the current colorway specified by CLO user.
		/// @return Return the list of the path of output files per colorway. 
		virtual vector< vector < string > > ExportRenderingImage(const string& _filePath, bool _bRenderAllColorways)
		{
			vector< vector < string > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportRenderingImage(bool _bRenderAllColorways)
		/// @brief Export Rendering Image.
		/// @param _bRenderAllColorways: If true, output the images for all colorways. Otherwise, it returns the images for the current colorway specified by CLO user.
		/// @return Return the list of the path of output files per colorway. 
		virtual vector< vector < string > > ExportRenderingImage(bool _bRenderAllColorways)
		{
			vector< vector < string > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportRenderingImageW(const wstring& _filePath, bool _bRenderAllColorways)
		/// @brief Export Rendering Image.
		/// @param _filePath: output file path
		/// @param _bRenderAllColorways: If true, output the images for all colorways. Otherwise, it returns the images for the current colorway specified by CLO user.
		/// @return Return the list of the path of output files per colorway. 
		virtual vector< vector < wstring > > ExportRenderingImageW(const wstring& _filePath, bool _bRenderAllColorways)
		{
			vector< vector < wstring > > interface_vector;
			return interface_vector;
		}

		/// @fn ExportSingleColorwayRenderingImage(const string& _filePath, unsigned int _colorwayIndex)
		/// @brief Export Rendering Image for the colorway
		/// @param _filePath: output file path
		/// @param _colorwayIndex: colorway index to render the image
		/// @return Return the list of the path of output files
		virtual vector < string > ExportSingleColorwayRenderingImage(const string& _filePath, unsigned int _colorwayIndex)
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn ExportSingleColorwayRenderingImage(unsigned int _colorwayIndex)
		/// @brief Export Rendering Image for the colorway
		/// @param _colorwayIndex: colorway index to render the image
		/// @return Return the list of the path of output files; output files will be created in CLO temporary folder.	
		virtual vector < string > ExportSingleColorwayRenderingImage(unsigned int _colorwayIndex)
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn ExportSingleColorwayRenderingImageW(const wstring& _filePath, unsigned int _colorwayIndex)
		/// @brief Export Rendering Image for the colorway
		/// @param _filePath: output file path
		/// @param _colorwayIndex: colorway index to render the image
		/// @return Return the list of the path of output files	
		virtual vector < wstring > ExportSingleColorwayRenderingImageW(const wstring& _filePath, unsigned int _colorwayIndex)
		{
			vector < wstring > interface_vector;
			return interface_vector;
		}

		/// @fn GetTotalRenderImagePaths()
		/// @brief Get File name list for all the exported rendering images
		/// @return all the rendered image file paths
		virtual vector < string >  GetTotalRenderImagePaths()
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn GetTotalRenderImagePathsW()
		/// @brief Get File name list for all the exported rendering images
		/// @return all the rendered image file paths
		virtual vector < wstring >  GetTotalRenderImagePathsW()
		{
			vector < wstring > interface_vector;
			return interface_vector;
		}

		/// @fn GetCurrentRenderImagePaths()
		/// @brief Current Render Image paths
		/// @return all current renderded image files paths per colorways
		virtual vector < string >  GetCurrentRenderImagePaths()
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn GetCurrentRenderImagePathsW()
		/// @brief Current Render Image paths
		/// @return all current renderded image files paths per colorways
		virtual vector < wstring >  GetCurrentRenderImagePathsW()
		{
			vector < wstring > interface_vector;
			return interface_vector;
		}

		/// @fn GetFileNameOnRenderingProperty()
		/// @return the output file names set on the Rendering Property in CLO
		virtual string GetFileNameOnRenderingProperty()
		{
			string str = "";
			return str;
		}

		/// @fn GetFileNameOnRenderingPropertyW()
		/// @return the output file names set on the Rendering Property in CLO
		virtual wstring GetFileNameOnRenderingPropertyW()
		{
			wstring str = L"";
			return str;
		}

		/// @fn ExportGarmentInformation()
		/// @brief Export garment information in json file. The information is the same as given in Garment Information Dialog in CLO (you can see this dialog by clicking File > Information > Garment menu in CLO)
		////@return Output file path. If an error occurs, return empty string; output files will be created in CLO temporary folder.
		virtual string ExportGarmentInformation() { return ""; }

		/// @fn ExportGarmentInformation(const string& _filePath)
		/// @brief Export garment information in json file. The information is the same as given in Garment Information Dialog in CLO (you can see this dialog by clicking File > Information > Garment menu in CLO)
		/// @param _filePath output file path to export the garment information
		////@return Output file path. If an error occurs, return empty string. 
		virtual string ExportGarmentInformation(const string& _filePath) { return ""; }

		/// @fn ExportGarmentInformationW(const wstring& _filePath)
		/// @brief Export garment information in json file. The information is the same as given in Garment Information Dialog in CLO (you can see this dialog by clicking File > Information > Garment menu in CLO)
		/// @param _filePath output file path to export the garment information
		////@return Output file path. If an error occurs, return empty string. 
		virtual wstring ExportGarmentInformationW(const wstring& _filePath) { return L""; }

		/// @fn ExportGarmentInformationToStream()
		/// @brief Export garment information in string
		/// @return Garment Information stream in sstring
		virtual string ExportGarmentInformationToStream() { return ""; }

		/// @fn ExportGarmentInformationToStreamW()
		/// @brief Export garment information in string as well as json file
		/// @return Garment Information stream in wstring
		virtual wstring ExportGarmentInformationToStreamW() { return L""; }
		
		/// @fn ExportGarmentInformationConfigData()
		/// @brief Export garment information config data in json file. The information is the same as given in "Conf_Garment_Information.json" file via Preference
		/// @return Output file path; the output files will be created in CLO temporary folder. If an error occurs, return empty string.
		virtual string ExportGarmentInformationConfigData() { return ""; }

		/// @fn ExportGarmentInformationConfigData(const string& _filePath)
		/// @brief Export garment information config data in json file. The information is the same as given in "Conf_Garment_Information.json" file via Preference
		/// @param _filePath output file path to export the garment information configuration data
		/// @return Output file path. If an error occurs, return empty string.
		virtual string ExportGarmentInformationConfigData(const string& _filePath) { return ""; }

		/// @fn ExportGarmentInformationConfigDataW(const wstring& _filePath)
		/// @brief Export garment information config data in json file. The information is the same as given in "Conf_Garment_Information.json" file via Preference
		/// @param _filePath output file path to export the garment information configuration data
		/// @return Output file path. If an error occurs, return empty string.
		virtual wstring ExportGarmentInformationConfigDataW(const wstring& _filePath) { return L""; }

		/// @fn ExportGarmentInformationConfigDataToStream()
		///	Export garment information configuration data in string
		/// @return Output stream for JSON data. If an error occurs, return empty string.
		virtual string ExportGarmentInformationConfigDataToStream() { return ""; }

		/// @fn ExportGarmentInformationConfigDataToStreamW()
		///	Export garment information configuration data in string
		/// @return Output stream for JSON data. If an error occurs, return empty string.
		virtual wstring ExportGarmentInformationConfigDataToStreamW() { return L""; }

		/// @fn ExportTurntableVideo()
		/// @brief Export turntable video. This function requires XVid Mpeg-4 codec installed on user's computer.
		/// @return Output file path; output files will be created in CLO temporary folder. If an error occurs, return empty string.
		virtual string ExportTurntableVideo() { return ""; }

		/// @fn ExportTurntableVideo(const string& _filePath)
		/// @brief Export turntable video. This function requires XVid Mpeg-4 codec installed on user's computer.
		/// @param _filePath 
		/// @return Output file path; output files will be created in CLO temporary folder. If an error occurs, return empty string.
		virtual string ExportTurntableVideo(const string& _filePath) { return ""; }

		/// @fn ExportTurntableVideoW(const wstring& _filePath)
		/// @brief Export turntable video. This function requires XVid Mpeg-4 codec installed on user's computer.
		/// @return Output file path; output files will be created in CLO temporary folder. If an error occurs, return empty string. 
		virtual wstring ExportTurntableVideoW(const wstring& _filePath) { return L""; }

		/// @fn ExportAnimationVideo()
		/// @brief Export animation video. This function requires XVid Mpeg-4 codec installed on user's computer.
		/// @return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual string ExportAnimationVideo() { return ""; }

		/// @fn ExportAnimationVideo()
		/// @brief Export animation video. This function requires XVid Mpeg-4 codec installed on user's computer.
		/// @return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual string ExportAnimationVideo(const string& _filePath) { return ""; }

		/// @fn ExportAnimationVideo()
		/// @brief Export animation video. This function requires XVid Mpeg-4 codec installed on user's computer.
		/// @return Output file path. If an error occurs, return empty string. If filePath parameter is not given, output files will be created in CLO temporary folder.
		virtual wstring ExportAnimationVideoW(const wstring& _filePath) { return L""; }

		//////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////

		/// @fn GetColorwayCount()
		/// @brief Get the number of colorways in the current garment loaded in CLO
		/// @return total count of colorways		
		virtual unsigned int GetColorwayCount() { return 0; }

		/// @fn GetCurrentColorwayIndex()
		/// @brief Get the index of the current colorway in CLO
		/// @return the current colorway index
		virtual unsigned int GetCurrentColorwayIndex() { return 0; }

		/// @fn GetColorwayNameList()
		/// @brief Get all the colorway names for the current garment 
		/// @return the list of name of all colorways
		virtual vector<string> GetColorwayNameList()
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn GetColorwayNameListW()
		/// @brief Get all the colorway names for the current garment 
		/// @return the list of name of all colorways
		virtual vector<wstring> GetColorwayNameListW()
		{
			vector < wstring > interface_vector;
			return interface_vector;
		}

		/// @fn GetAvatarCount()
		/// @brief Get the number of avatars loaded in CLO
		/// @return total count of avatars		
		virtual unsigned int GetAvatarCount() { return 0; }

		/// @fn GetAvatarNameList()
		/// @brief Get all the names of avatars loaded in CLO
		/// @return the list of name of all avatars
		virtual vector<string> GetAvatarNameList()
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn GetAvatarNameListW()
		/// @brief Get all the names of avatars loaded in CLO
		/// @return the list of name of all avatars
		virtual vector<wstring> GetAvatarNameListW()
		{
			vector < wstring > interface_vector;
			return interface_vector;
		}

		/// @fn GetAvatarGenderList()
		/// @brief Get all the genders of avatars loaded in CLO repectively
		/// @return the list of gender of all avatars. 0 : male, 1 : female, -1: unknown
		virtual vector<int> GetAvatarGenderList()
		{
			vector < int > interface_vector;
			return interface_vector;
		}

		/// @fn GetSizeCount()
		/// @brief Get the number of sizes/gradings
		/// @return total count of sizes/gradings
		virtual unsigned int GetSizeCount() { return 0; }

		/// @fn GetCurrentSizeIndex()
		/// @brief Get the index of the current size/grading
		/// @return the current index of size/grading
		virtual unsigned int GetCurrentSizeIndex() { return 0; }

		/// @fn GetSizeNameList()
		/// @brief Get the index of the current size/grading
		/// @return the list of name of all sizes/gradings
		virtual vector<string> GetSizeNameList()
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn GetSizeNameListW()
		/// @brief Get the index of the current size/grading
		/// @return the list of name of all sizes/gradings
		virtual vector<wstring> GetSizeNameListW()
		{
			vector < wstring > interface_vector;
			return interface_vector;
		}
		
		/// @fn ExportTurntableImages(int _numberOfImages)
		/// @brief Export turntable images for current colorway.
		/// @param _numberOfImages: the number of images in 360 turn table. The turn table will turn by (360 / _numberOfImages) per an image each by each.
		/// @return Output file path list; output files will be created in CLO temporary folder. If an error occurs, return empty string.
		virtual vector<string> ExportTurntableImages(int _numberOfImages)
		{
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn ExportTurntableImages(const string& _filePath, int _numberOfImages, int _width = 2500, int _height = 2500) 
		/// @brief Export turntable images for current colorway.
		/// @param _filePath: the output file path to export the turntable snapshots
		/// @param _numberOfImages: the number of images in 360 turn table. The turn table will turn by (360 / _numberOfImages) per an image each by each.
		/// @param _width: image width for the snapshots
		/// @param _height: image height for the snapshots
		/// @return Output file path list. If an error occurs, return empty string. 
		virtual vector<string> ExportTurntableImages(const string& _filePath, int _numberOfImages, int _width = 2500, int _height = 2500) 
		{ 
			vector < string > interface_vector;
			return interface_vector;
		}

		/// @fn ExportTurntableImagesW(const wstring& _filePath, int _numberOfImages, int _width = 2500, int _height = 2500)
		/// @brief Export turntable images for current colorway.
		/// @param _filePath: the output file path to export the turntable snapshots
		/// @param _numberOfImages: the number of images in 360 turn table. The turn table will turn by (360 / _numberOfImages) per an image each by each.
		/// @param _width: image width for the snapshots
		/// @param _height: image height for the snapshots
		/// @return Output file path list. If an error occurs, return empty string. 
		virtual vector<wstring> ExportTurntableImagesW(const wstring& _filePath, int _numberOfImages, int _width = 2500, int _height = 2500)
		{ 
			vector < wstring > interface_vector;
			return interface_vector;
		}

		/// @fn ExportGLB(const string& _filePath, const Marvelous::ImportExportOption& _options)
		///	@brief Export GLB
		///	@param options: If "options" is given, it exports GLB according to options, not allowing user for selecting options in Export Dialog.
		///	@return Output file paths. 
		virtual vector<string> ExportGLB(const string& _filePath, const Marvelous::ImportExportOption& _options)
		{
			vector<string> interface_vector;
			return interface_vector;
		}

		/// @fn ExportGLBW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		///	@brief Export GLBW
		///	@param options: If "options" is given, it exports GLB according to options, not allowing user for selecting options in Export Dialog.
		///	@return Output file paths. 
		virtual vector<wstring> ExportGLBW(const wstring& _filePath, const Marvelous::ImportExportOption& _options)
		{
			vector<wstring> interface_vector;
			return interface_vector;
		}
	};
}
