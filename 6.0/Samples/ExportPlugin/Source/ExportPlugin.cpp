#include "stdafx.h"

#include "ExportPlugin.h"

#include "CLOAPIInterface.h"

#include <string>
#include <fstream>
#include <map>

#if defined(__APPLE__)
#include <unistd.h>
#include <pwd.h>
#endif

// Test Codes in DoFunctions (0: Deactivate, 1: Activate)
#define USE_RENDERINGIMAGE_SAMPLE						0
#define USE_EXPORT_TECHPACK_SAMPLE						0
#define USE_EXPORT_OBJ_SAMPLE							0
#define USE_EXPORT_ZPRJ_SAMPLE							0
#define USE_FABRIC_SAMPLE								0
#define USE_PROGRESSBAR_SAMPLE							0
#define USE_EXPORT_SIMULATION_SAMPLE					0
#define USE_GET_INFORMATIONS_SAMPLE						0
#define USE_GET_CUSTOM_VIEW_SAMPLE						0
#define USE_COLORWAY_NAME_SAMPLE						0
#define USE_REST_API_TEST								0
#define USE_UNICODE_FUNCTION_TEST						0
#define USE_ADD_COLORCHIP_TEST							0
#define USE_NEW_PROJECT_TEST							0
#define USE_FABRIC_FILE_METADATA_TEST					0
#define USE_GET_CLO_FILE_PATH_TEST						0
#define USE_EXPORT_TURNTABLE_IMAGES						0
#define USE_EXPORT_GLTF_TEST							0
#define USE_EXPORT_TURNTABLE_VIDEO						0
#define USE_READ_WRITE_METADATA_FILE					0
#define USE_SET_WINDOWS_TITLE_3D_TEST					0
#define USE_COPY_COLORWAY_TEST							0
#define USE_GARMENT_INFO_TEST							0
#define USE_GARMENT_INFO_CONFIG_TEST					0
#define USE_EXPORT_TECHPACK_TO_STREAM_TEST				0
#define USE_EXPORT_THUMBNAIL3D_TEST						0
#define USE_EXPORT_SNAPSHOT3D_TEST						0
#define USE_EXPORT_SINGLE_COLORWAY_RENDERING_IMAGE_TEST 0
#define USE_GET_RENDER_IMAGE_RELATED_PATHS_TEST			0
#define USE_GET_FILE_NAME_ON_RENDERING_PROPERTY_TEST	0
#define USE_GET_COLORWAY_RELATED_INFORMATION_TEST		0
#define USE_GET_SIZE_RELATED_INFORMATION_TEST			0
#define USE_GET_FABRIC_RELATED_INFORMATION_TEST			0
#define USE_CHANGE_FABRIC_WITH_JSON_TEST				0
#define USE_ASSIGN_FABRIC_TO_PATTERN_TEST				0
#define USE_EXPORT_ANIMATION_VIDEO						0
#define USE_IMPORT_ZPRJ_SAMPLE							0
#define USE_IMPORT_FILE_SAMPLE							0
#define USE_EXPORT_ZPAC_TEST							0
#define USE_AVATAR_RELATED_API_TEST						0
#define USE_PATTERN_RELATED_API_TEST					0
#define USE_VERSION_CHECK_API_TEST						0
#define USE_EXPORT_GLB_TEST								0

using namespace std;
using namespace CLOAPI;

static std::string base64_encode(const std::string &in) {

	std::string out;

	int val = 0, valb = -6;
	for (unsigned char c : in) {
		val = (val << 8) + c;
		valb += 8;
		while (valb >= 0) {
			out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val >> valb) & 0x3F]);
			valb -= 6;
		}
	}
	if (valb > -6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val << 8) >> (valb + 8)) & 0x3F]);
	while (out.size() % 4) out.push_back('=');
	return out;
}

string getHomePath()
{
	string homePath = "C:/";

#if defined(__APPLE__)
	const char *homeDir = getenv("HOME");

	if (homeDir == nullptr)
	{
		struct passwd* pwd = getpwuid(getuid());
		if (pwd)
		   homeDir = pwd->pw_dir;
	}

	if (homeDir)
    {
		homePath = homeDir;
        homePath = homePath + "/";
    }
	else
    {
		homePath = "/usr/local/";
    }
#endif

	return homePath;
}

void ExportZprjSample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	string exportPath = UTILITY_API->GetCLOTemporaryFolderPath() + "test.zprj";
	EXPORT_API->ExportZPrj(exportPath, true);

	string msg = "Export Zprj Complete: " + exportPath;
	UTILITY_API->DisplayMessageBox(msg);
}

void ExportTechPack_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	fprintf(stdout, "Start Export Tech Pack !! ========================== \n");

	string exportPath = UTILITY_API->GetCLOTemporaryFolderPath() + "test.json";
	string baseFolder = getHomePath() + "Zpac/";

	exportPath = baseFolder + "test1/test.json";
	Marvelous::ExportTechpackOption option(Marvelous::CLO_DUMMY);

	// set flags for 3D Baseline for capturing
	option.m_ShowBaseLineFor3DCapturePerColorway[0] = false;
	option.m_ShowBaseLineFor3DCapturePerColorway[1] = true;
	option.m_ShowBaseLineFor3DCapturePerColorway[2] = false;
	//option.m_ShowBaseLineFor3DCapturePerColorway[3] = true; - as-is

	EXPORT_API->ExportTechPack(exportPath, option);

	//
	exportPath = baseFolder + "test2/test.json";
	option.m_bUseAverageColor = true;
	EXPORT_API->ExportTechPack(exportPath, option);

	//
	exportPath = baseFolder + "test3/test.json";
	option.m_bUseAverageColor = false;

	option.m_bCapturePatternLayoutThumbnailWithFabricMark = true;
	option.m_bCapturePatternLayoutThumbnailWithTrimMark = true;
	EXPORT_API->ExportTechPack(exportPath, option);

	//
	exportPath = baseFolder + "test4/test.json";
	option.m_bCaptureItemThumbnail = true;
	option.m_bCapturePatternLayoutThumbnailWithTrimMark = true;
	EXPORT_API->ExportTechPack(exportPath, option);

	//
	exportPath = baseFolder + "test5/test.json";
	option.m_bCaptureSceneThumbnailWithoutAvatar = true;
	option.m_bCaptureSceneThumbnailWithMark = true;
	option.m_bCaptureSceneThumbnailWithAvatar = true;
	EXPORT_API->ExportTechPack(exportPath, option);

	//
	exportPath = baseFolder + "test6/test.json";
	option.m_bSaveZpac = true;
	option.m_bSaveZprj = true;
	EXPORT_API->ExportTechPack(exportPath, option);

	fprintf(stdout, "========================== END of the TEST ========================== \n");
}

void ExportTechPackW_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	fprintf(stdout, "Start Export Tech Pack !! ========================== \n");

	string baseFolder = getHomePath() + "Zpac/";

	wstring exportPath = UTILITY_API->GetCLOTemporaryFolderPathW() + L"test.json";
	wstring baseFolderW(baseFolder.begin(), baseFolder.end());

	exportPath = baseFolderW + L"테스트1/테스트.json";
	Marvelous::ExportTechpackOption option(Marvelous::CLO_DUMMY);

	EXPORT_API->ExportTechPackW(exportPath, option);

	//
	exportPath = baseFolderW + L"테스트2/테스트.json";
	option.m_bUseAverageColor = true;
	EXPORT_API->ExportTechPackW(exportPath, option);

	//
	exportPath = baseFolderW + L"테스트3/테스트.json";
	option.m_bUseAverageColor = false;

	option.m_bCapturePatternLayoutThumbnailWithFabricMark = true;
	option.m_bCapturePatternLayoutThumbnailWithTrimMark = true;
	EXPORT_API->ExportTechPackW(exportPath, option);

	//
	exportPath = baseFolderW + L"테스트4/테스트.json";
	option.m_bCaptureItemThumbnail = true;
	option.m_bCapturePatternLayoutThumbnailWithTrimMark = true;
	EXPORT_API->ExportTechPackW(exportPath, option);

	//
	exportPath = baseFolderW + L"테스트5/테스트.json";
	option.m_bCaptureSceneThumbnailWithoutAvatar = true;
	option.m_bCaptureSceneThumbnailWithMark = true;
	option.m_bCaptureSceneThumbnailWithAvatar = true;
	EXPORT_API->ExportTechPackW(exportPath, option);

	//
	exportPath = baseFolderW + L"테스트6/테스트.json";
	option.m_bSaveZpac = true;
	option.m_bSaveZprj = true;
	EXPORT_API->ExportTechPackW(exportPath, option);

	wstring techpack_stream = EXPORT_API->ExportTechPackToStreamW(exportPath);
	UTILITY_API->DisplayMessageBoxW(techpack_stream);
	UTILITY_API->DisplayMessageBoxW(exportPath);

	fprintf(stdout, "========================== END of the TEST ========================== \n");
}

void HttpGetTest()
{
	if (!REST_API)
		return;

	string id = ""; // set the clo id
	string pw = ""; // set the clo pw
	pw = UTILITY_API->stringToMD5(pw); // change the clo pw with md5 hashed in lower cases

	string basicAuthorizationString = "Basic " + base64_encode(id + ":" + pw);

	vector<pair<string, string>> headerNameAndValueList;
	headerNameAndValueList.push_back(make_pair("Authorization", basicAuthorizationString));
	headerNameAndValueList.push_back(make_pair("X-User-Product", "24"));

	string url = "https://api.clo3d.com/auth/versioncheck?version=2.5.9999.299999&product=24&ostype=2207&processbit=3001";
	string response = REST_API->CallRESTGet(url, headerNameAndValueList, "HTTP Get");
	fprintf(stdout, "\n\n");
	fprintf(stdout, response.c_str());
	fprintf(stdout, "\n\n");

	UTILITY_API->DisplayMessageBox(response);

	unsigned char* buffer = nullptr;
	unsigned int size = 0;

	REST_API->GetByteArrayFromStream(response, buffer, size);

	string str((const char*)buffer);
	UTILITY_API->DisplayMessageBox(str);

	UTILITY_API->DisplayMessageBox(to_string(size));

	delete buffer;
	buffer = nullptr;
	size = 0;
}

void HttpPostTest()
{
	if (!REST_API)
		return;

	string id = ""; // set the clo id
	string pw = ""; // set the clo pw with md5 hashed in lower cases
	string basicAuthorizationString = "Basic " + base64_encode(id + ":" + pw);

	vector<pair<string, string>> headerNameAndValueList;
	headerNameAndValueList.push_back(make_pair("Host", "api.clo3d.com"));
	headerNameAndValueList.push_back(make_pair("Authorization", basicAuthorizationString));
	headerNameAndValueList.push_back(make_pair("Cache-Control", "no-cache"));
	headerNameAndValueList.push_back(make_pair("Content-Type", "application/x-www-form-urlencoded"));
	headerNameAndValueList.push_back(make_pair("X-User-Product", "24"));

	string parameter = "userid=kylelee&password=2ce46905cb1530c3c1e2149634854ce4&product=24&version=2.5.9999.299999";

	string response = REST_API->CallRESTPost("https://api.clo3d.com/auth/login", &parameter, headerNameAndValueList, "HTTP Post test");
	fprintf(stdout, "\n\n");
	fprintf(stdout, response.c_str());
	fprintf(stdout, "\n\n");
}

void HttpPost2Test()
{
	if (!REST_API)
		return;

	string id = ""; // set the clo id
	string pw = ""; // set the clo pw with md5 hashed in lower cases
	string basicAuthorizationString = "Basic " + base64_encode(id + ":" + pw);

	vector<pair<string, string>> headerNameAndValueList;
	headerNameAndValueList.push_back(make_pair("Host", "api.clo3d.com"));
	headerNameAndValueList.push_back(make_pair("Authorization", basicAuthorizationString));
	headerNameAndValueList.push_back(make_pair("Cache-Control", "no-cache"));
	headerNameAndValueList.push_back(make_pair("Content-Type", "application/x-www-form-urlencoded"));
	headerNameAndValueList.push_back(make_pair("X-User-Product", "24"));

	string parameter = "userid=kylelee&password=2ce46905cb1530c3c1e2149634854ce4&product=24&version=2.5.9999.299999";

	unsigned char *postField = new unsigned char[parameter.length() + 1];
	std::strcpy((char*)postField, parameter.c_str());
	unsigned int size = (unsigned int)(parameter.length()) + 1;

	string response = REST_API->CallRESTPost2("https://api.clo3d.com/auth/login", postField, size, headerNameAndValueList, "HTTP Post2 test");
	fprintf(stdout, "\n\n");
	fprintf(stdout, response.c_str());
	fprintf(stdout, "\n\n");
}

void UploadToCLOSET(const string& filePath)
{
	if (!REST_API)
		return;

	vector<pair<string, string>> headerNameAndValueList;

	string response = REST_API->CallRESTPostWithMultipartFormData("https://www.clo-set.com/api/item", filePath, headerNameAndValueList, "Upload...");
	fprintf(stdout, "\n\n");
	fprintf(stdout, response.c_str());
	fprintf(stdout, "\n\n");
	UTILITY_API->DisplayMessageBox(response);
}

void ExportThumbnail3D_Sample()
{
	if (!EXPORT_API)
		return;

	EXPORT_API->ExportThumbnail3D();
}

void ExportSnapshot3D_Sample()
{
	if (!EXPORT_API)
		return;

	EXPORT_API->ExportSnapshot3D();
}

void ExportGarmentInformation_Sample()
{
	if (!EXPORT_API)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	string filePath = baseFolder + "info.json";

	EXPORT_API->ExportGarmentInformation(filePath);
}

void ImportGarmentInformation_Sample()
{
	if (!IMPORT_API)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	string filePath = baseFolder + "info.json";

	IMPORT_API->ImportGarmentInformation(filePath);
}

void ExportGarmentInformationConfigData_Sample()
{
	if (!EXPORT_API)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	string filePath = baseFolder + "configData.json";

	EXPORT_API->ExportGarmentInformationConfigData(filePath);
}

void ImportGarmentInformationConfigData_Sample()
{
	if (!IMPORT_API)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	string filePath = baseFolder + "configData.json";

	IMPORT_API->ImportGarmentInformationConfigData(filePath);
}

void ExportRenderingImage_Sample()
{
	if (!EXPORT_API)
		return;

	vector< vector<std::string>> savedFilePathList = EXPORT_API->ExportRenderingImage(true);
}

void ExportOBJ_Sample()
{
	if (!EXPORT_API)
		return;

	Marvelous::ImportExportOption options;
	options.bExportAvatar = false;
	options.bExportGarment = true;
	options.bSaveInZip = true;
	// the other options are given as default. please refer to ImportExportOption class in ExportAPI.h

	vector<string> exportedFilePathList;
	if (options.bSaveInZip)
	{
		string baseFolder = getHomePath() + "Zpac/";
		exportedFilePathList = EXPORT_API->ExportOBJ(baseFolder + "test.obj", options); // returns only a file path for a zipped file including OBJ, MTL, and image files.

		// exportedFilePathList[0] -> a zip file

	}
	else
	{
		exportedFilePathList = EXPORT_API->ExportOBJ(options); // returns OBJ and MTL files. In addition, MTL files for colorways will be created as well.

		// exportedFilePathList[0] -> OBJ
		// exportedFilePathList[1] -> MTL for the current colorway
		// exportedFilePathList[2] -> MTL for the first colorway
		// exportedFilePathList[3] -> MTL for the second colorway
		// ...
		// exportedFilePathList[exportedFilePathList.size()-1]-> MTL for the last colorway
	}

	for (auto& path : exportedFilePathList)
	{
		if (UTILITY_API)
			UTILITY_API->DisplayMessageBox(path);
	}

}

void ExportDXF_Sample()
{
	Marvelous::ExportDxfOption exportOption;
	exportOption.m_RotateAngle = 90;
	exportOption.m_fScale = 2.0f;

	string baseFolder = getHomePath() + "export_dxf/";

	if (EXPORT_API)
		EXPORT_API->ExportDXF(baseFolder + "test.dxf", exportOption);
}

//void ExportSimulation_Sample()
//{
//	if (!EXPORT_API || !UTILITY_API)
//		return;
//
//	string logFilePath = "C:/Zpac/log.txt";
//	FILE* LOG_FILE = fopen(logFilePath.c_str(), "w");
//
//	if (LOG_FILE == nullptr)
//	{
//		UTILITY_API->DisplayMessageBox("Please make sure the log file is not opened by other programs.");
//		return;
//	}
//
//	fprintf(LOG_FILE, "Start ExportSimulation_Sample\n");
//
//	// Change physical properties on Fabric #0
//	//FABRIC_API->ChangeFabricFromJson(0, );
//
//	// Assign Fabric #0 to the pattern #0
//	//FABRIC_API->AssignFabricToPattern(0, 0);
//
//	UTILITY_API->CreateProgressBar();
//	UTILITY_API->SetProgress("Testing...", 0);
//
//	// Simulation(in fixed times)
//	vector<float> clothPositions;
//	for (unsigned int simIter = 0; simIter < 10; simIter++)
//	{
//		fprintf(LOG_FILE, "SimIter : %d\n", simIter);
//
//		UTILITY_API->SimulateOneStep();
//
//		// check if the simulation is converged. First, get the result positions.
//		UTILITY_API->GetClothPositions(clothPositions);
//		// convergence check code here. 
//
//		//
//		UTILITY_API->SetProgress("Testing...", simIter * 10);
//
//		for (size_t i = 0; i < clothPositions.size(); ++i)
//			fprintf(LOG_FILE, "clothPositions %d: %.2f\n", i, clothPositions[i]);
//
//		if (GetAsyncKeyState(VK_LEFT))
//			break;
//	}
//
//	// Save snapshot
//	string imageFilePath = "C:/Zpac/test.png";
//	vector<string> outputPath =	EXPORT_API->ExportCustomViewSnapshot(imageFilePath, 512, 512, "sample");
//
//	//Reset the cloth shape(Restore the shape to before the simulation)
//	UTILITY_API->ResetClothArrangement();
//
//	UTILITY_API->DeleteProgressBar(false);
//
//	fprintf(LOG_FILE, "End ExportSimulation_Sample\n");
//	fprintf(LOG_FILE, "\n");
//	fclose(LOG_FILE);
//}


void ExportFabric_Sample()
{
	if (FABRIC_API == nullptr)
		return;

	int index = 0; // default fabric, the 1st fabric on the object browser in CLO S/W

	string baseFolder = getHomePath() + "fabric/";
	string jFabFilePath = baseFolder + "test.jfab";
	string zFabFilePath = baseFolder + "test.zfab";

	FABRIC_API->ExportZFab(jFabFilePath, index);
	FABRIC_API->ExportZFab(zFabFilePath, index);

}

void ImportFabric_Sample()
{
	if (FABRIC_API == nullptr)
		return;

	string baseFolder = getHomePath() + "fabric/";
	string jFabFilePath = baseFolder + "test.jfab";
	string zFabFilePath = baseFolder + "test.zfab";

	unsigned int addedFabricIndexFromJson = FABRIC_API->AddFabric(jFabFilePath);
	unsigned int addedFabricIndexFromZfab = FABRIC_API->AddFabric(zFabFilePath);

	string xTexFilePath = baseFolder + "test.xTex"; // use any xTex file(with textures folder) you have

	FABRIC_API->ImportXtexFile(addedFabricIndexFromJson, xTexFilePath);
	FABRIC_API->ImportXtexFile(addedFabricIndexFromZfab, xTexFilePath);
	FABRIC_API->ApplyXtexFile(addedFabricIndexFromJson, xTexFilePath);
	FABRIC_API->ApplyXtexFile(addedFabricIndexFromZfab, xTexFilePath);
}

void DeleteFabric_Sample()
{
	if (FABRIC_API == nullptr)
		return;

	const string fabricName = "CLO_FABRIC_2019_1";

	int fabricIndex = FABRIC_API->GetFabricIndex(fabricName);

	if (fabricIndex > 0) // 0 is default fabric
		FABRIC_API->DeleteFabric(fabricIndex);
}

string GetSampleMetaData()
{
	string sampleMetaData = "{\n"; // start element	
	sampleMetaData += "\"itemID\": \"CLO_GR_2019_09_30_001\""; // itemId
	sampleMetaData += ",\n";
	sampleMetaData += "\"serviceDivision\": \"CLO Service Division\""; // service division
	sampleMetaData += ",\n";
	sampleMetaData += "\"brand\": \"CLO Luxury\""; // brand
	sampleMetaData += ",\n";
	sampleMetaData += "\"productType\": \"Blazer\""; // product type
	sampleMetaData += "\n}\n"; // end element

	return sampleMetaData;
}

void GarmentMetaData_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	// sample meta data
	string sampleMetaData = GetSampleMetaData();

	// set sample meta data
	UTILITY_API->SetMetaDataForCurrentGarment(sampleMetaData);

	// get sample meta data
	string curMetaData = UTILITY_API->GetMetaDataForCurrentGarment();
	UTILITY_API->DisplayMessageBox(curMetaData);

	// change sample meta data
	string metaDataKey1 = "serviceDivision";
	string newValue1 = "MD Service Division";

	string metaDataKey2 = "brand";
	string newValue2 = "MD CG Studio";

	UTILITY_API->ChangeMetaDataValueForCurrentGarment(metaDataKey1, newValue1);
	UTILITY_API->ChangeMetaDataValueForCurrentGarment(metaDataKey2, newValue2);
	UTILITY_API->DisplayMessageBox(UTILITY_API->GetMetaDataForCurrentGarment());
}

void FabricMetaData_Sample()
{
	if (UTILITY_API == nullptr || FABRIC_API == nullptr)
		return;

	// sample meta data
	string sampleMetaData = GetSampleMetaData();

	FABRIC_API->SetAPIMetaData(1, sampleMetaData);
	FABRIC_API->ChangeMetaDataValueForFabric(1, "testKey", "testValue");

	string apiMetaData = FABRIC_API->GetAPIMetaData(1);
	UTILITY_API->DisplayMessageBox(apiMetaData);
}

void ProgressBar_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	UTILITY_API->CreateProgressBar();

	for (int i = 0; i < 10; ++i)
	{
		UTILITY_API->SetProgress("Progress... ", (int)(float(i) / 10.0f * 100));
#ifdef __APPLE__ 
		sleep(1);
#else
		Sleep(200);
#endif
	}

	UTILITY_API->DeleteProgressBar(false);
}

void GetInformations_Sample()
{
	string fabricInfo = FABRIC_API->GetColorwayFabricInfo(0, 0);
	UTILITY_API->DisplayMessageBox(fabricInfo);

	string patternInfo = PATTERN_API->GetPatternInformation(0);
	UTILITY_API->DisplayMessageBox(patternInfo);
}

void GetCustomView_Sample()
{
	string customViewInfo = UTILITY_API->GetCustomViewInformation();
	UTILITY_API->DisplayMessageBox(customViewInfo);
}

void ColorwayName_Sample()
{
	// colorway count
	unsigned int colorwayCount = UTILITY_API->GetColorwayCount();
	string msg = "Colorway Count: " + to_string(colorwayCount);
	UTILITY_API->DisplayMessageBox(msg);

	// current colorway index
	unsigned int currentColorwayIndex = UTILITY_API->GetCurrentColorwayIndex();
	msg = "Current Colorway Index: " + to_string(currentColorwayIndex);
	UTILITY_API->DisplayMessageBox(msg);

	// colorway name
	wstring wName = UTILITY_API->GetColorwayNameW(UTILITY_API->GetCurrentColorwayIndex());
	wName = L"Current Colorway Name: " + wName;
	UTILITY_API->DisplayMessageBoxW(wName);

	wName = L"WAPITEST_ColorwayName";
	UTILITY_API->SetColorwayNameW(currentColorwayIndex, wName);
	UTILITY_API->RefreshColorwayDialog();

	// set colorway index test
	UTILITY_API->SetCurrentColorwayIndex(1);
	currentColorwayIndex = UTILITY_API->GetCurrentColorwayIndex();
	msg = "Current Colorway Index: " + to_string(currentColorwayIndex);
	UTILITY_API->DisplayMessageBox(msg);

	wName = UTILITY_API->GetColorwayNameW(UTILITY_API->GetCurrentColorwayIndex());
	wName = L"Current Colorway Name: " + wName;
	UTILITY_API->DisplayMessageBoxW(wName);
}

void UnicodeFunctionsTest()
{
	wofstream fi;
#ifdef __APPLE__ 
	string baseFolder = getHomePath() + "Zpac/";
	string test_log_file = baseFolder + "log.txt";
	fi.imbue(locale("ko_KR.UTF-8"));
	fi.open((const char*)test_log_file.c_str());
#else
	wstring test_log_file = L"C:/Zpac/log.txt";
	fi.imbue(locale("ko_KR.UTF-8"));
	fi.open(test_log_file);
#endif

	/// Fabric API test
	fi << L"############# Start Fabric API Test ########### " << endl;

	// ExportZFabW
	fi << L"wstring ExportZFabW" << endl;

#ifdef __APPLE__ 
	string zfabFilePath = baseFolder + "test.zfab";
	wstring zfabFilePathW(zfabFilePath.begin(), zfabFilePath.end());
#else
	wstring zfabFilePathW = L"C:\\Zpac\\test.zfab";
#endif

	wstring retValue = FABRIC_API->ExportZFabW(zfabFilePathW, 0);

	fi << L"Exported ZFab file " << endl;
	fi << L"--> Value : " << retValue << endl;

	fi << endl;

	// ExportFabricW
	fi << L"wstring ExportFabricW" << endl;

#ifdef __APPLE__ 
	string jfabFilePath = baseFolder + "test.jfab";
	wstring jfabFilePathW(jfabFilePath.begin(), jfabFilePath.end());
#else
	wstring jfabFilePathW = L"C:\\Zpac\\test.jfab";
#endif

	retValue = FABRIC_API->ExportFabricW(jfabFilePathW, 0);

	fi << L"Exported Fabric file " << endl;
	fi << L"--> Value : " << retValue << endl;

	fi << endl;

	// AddFabricW
	fi << L"unsigned int AddFabricW" << endl;

	unsigned int fabricIndex = FABRIC_API->AddFabricW(zfabFilePathW);

	fi << L"Added Fabric Index for " << zfabFilePathW << endl;
	fi << L"--> Value : " << to_wstring(fabricIndex) << endl;

	fi << endl;

	// GetFirstFabricTextureNameW
	fi << L"wstring GetFirstFabricTextureNameW" << endl;
	wstring firstTextureName = FABRIC_API->GetFirstFabricTextureNameW();

	fi << L"First Fabric Texture Name for the current colorway" << endl;
	fi << L"--> Value : " << firstTextureName << endl;

	fi << endl;

	// GetFirstFabricTextureNameW for colorway
	fi << L"wstring GetFirstFabricTextureNameW for colorway index" << endl;
	unsigned int colorwayIndex = 0;
	firstTextureName = FABRIC_API->GetFirstFabricTextureNameW(colorwayIndex);

	fi << L"First Fabric Texture Name for the colorway, " << to_wstring(colorwayIndex) << endl;
	fi << L"--> Value : " << firstTextureName << endl;

	fi << endl;

	wstring fabricName = FABRIC_API->GetFabricNameW(0);
	UTILITY_API->DisplayMessageBoxW(fabricName);

	// GetFabricNameW
	fi << L"Fabric Name for Index 0 " << endl;
	fi << L"--> Value : " << fabricName << endl;

	fi << endl;

	// GetFabricIndexW
	fabricIndex = FABRIC_API->GetFabricIndexW(fabricName);
	fi << L"Fabric index for " << fabricName << endl;
	fi << L"--> Value : " << to_wstring(fabricIndex) << endl;

	// GetColorwayFabricInfoW
	wstring fabricInfo = FABRIC_API->GetColorwayFabricInfoW(colorwayIndex, fabricIndex);
	fi << L"Fabric Information for Coloraway Index: " << to_wstring(colorwayIndex) << L", Fabric Index: " << to_wstring(fabricIndex) << endl;
	fi << fabricInfo << endl << endl;

	fi << L"############# Finalize Fabric API Test ########### " << endl;

	/// Pattern API test
	fi << L"############# Start Pattern API Test ########### " << endl;
	unsigned int patternIndex = 0;
	wstring patternInfo = PATTERN_API->GetPatternInformationW(patternIndex);
	fi << L"Pattern Information for Pattern Index: " << to_wstring(patternIndex) << endl;
	fi << patternInfo << endl << endl;
	UTILITY_API->DisplayMessageBoxW(patternInfo);

	fi << L"############# Finalize Pattern API Test ########### " << endl;

	/// Export API test
	fi << L"############# Start Export API Test ########### " << endl;
	wstring garmentInfo = EXPORT_API->ExportGarmentInformationToStreamW();
	fi << L"Garment Information: " << endl;
	fi << garmentInfo << endl << endl;
	UTILITY_API->DisplayMessageBoxW(garmentInfo);

	wstring garmenetConfigData = EXPORT_API->ExportGarmentInformationConfigDataToStreamW();
	fi << L"Garment Information Config Data : " << endl;
	fi << garmenetConfigData << endl << endl;
	UTILITY_API->DisplayMessageBoxW(garmenetConfigData);

	wstring techpackOutputPath;
	wstring techpackInfo = EXPORT_API->ExportTechPackToStreamW(techpackOutputPath);
	fi << L"Techpack Information: " << endl;
	fi << techpackInfo << endl << endl;
	UTILITY_API->DisplayMessageBoxW(techpackInfo);

	fi << L"############# Finalize Export API Test ########### " << endl;

	/// Utility API test	
	fi << L"############# Start Utility API Test ########### " << endl;
	wstring tempFolder = UTILITY_API->GetCLOTemporaryFolderPathW();
	fi << L"CLO Temporary folder created : " << endl;
	fi << tempFolder << endl;

	wstring projectName = UTILITY_API->GetProjectNameW();
	fi << L"Project Name : " << endl;
	fi << projectName << endl;

	wstring projectFilePath = UTILITY_API->GetProjectFilePathW();
	fi << L"Project File Path : " << endl;
	fi << projectFilePath << endl;

	wstring customViewInfo = UTILITY_API->GetCustomViewInformationW();
	fi << L"Custom View Information: " << endl;
	fi << customViewInfo << endl << endl;
	UTILITY_API->DisplayMessageBoxW(customViewInfo);

	fi << L"############# Finalize Utility API Test ########### " << endl;

	fi.close();

#ifdef __APPLE__
	UTILITY_API->DisplayMessageBox(test_log_file);
#else
	UTILITY_API->DisplayMessageBoxW(test_log_file);
#endif
}

void GetCustomViewWithZcmrTest()
{
	vector<wstring> cameraFiles;

	string baseFolder = getHomePath() + "Zpac/";
	wstring baseFolderW(baseFolder.begin(), baseFolder.end());

	cameraFiles.push_back(baseFolderW + L"Custom_View_1.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_2.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_3.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_4.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_5.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_6.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_7.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_8.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_9.zcmr");
	cameraFiles.push_back(baseFolderW + L"Custom_View_10.zcmr");

	for (size_t i = 0; i < cameraFiles.size(); ++i)
		IMPORT_API->ImportFileW(cameraFiles[i]);

	string imageFilePath = baseFolder + "output_image";
	vector<string> outputPath = EXPORT_API->ExportCustomViewSnapshot(imageFilePath, 512, 512, "sample");
}

void AddColorChip_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	wstring swatchName = L"CLO_API_CUSTOM_SWATCH";
	map<wstring, wstring> plmIdToNameList;
	map<wstring, Marvelous::CloApiRgb> plmIdToColorList;
	map<wstring, wstring> plmIdToApiMetaDataList;

	Marvelous::CloApiRgb color;
	color.R = 255;

	// 1. red
	plmIdToNameList[L"CLO_API_RED"] = L"CLO_API_RED";
	plmIdToColorList[L"CLO_API_RED"] = color;

	wstring apiMetaData = L"{\r\n\"KEY1_FOR_RED\":\"CLO_API_RED_VALUE1\", \r\n\"KEY2_FOR_RED\":\"CLO_API_RED_VALUE2\"}";
	plmIdToApiMetaDataList[L"CLO_API_RED"] = apiMetaData;

	// 2. green
	color.R = 0;
	color.G = 255;

	plmIdToNameList[L"CLO_API_GREEN"] = L"CLO_API_GREEN";
	plmIdToColorList[L"CLO_API_GREEN"] = color;

	apiMetaData = L"{\r\n\"KEY1_FOR_GREEN\":\"CLO_API_GREEN_VALUE1\", \r\n\"KEY2_FOR_GREEN\":\"CLO_API_GREEN_VALUE2\"}";
	plmIdToApiMetaDataList[L"CLO_API_GREEN"] = apiMetaData;

	// 3. blue
	color.R = 0;
	color.G = 0;
	color.B = 255;

	plmIdToNameList[L"CLO_API_BLUE"] = L"CLO_API_BLUE";
	plmIdToColorList[L"CLO_API_BLUE"] = color;

	apiMetaData = L""; // empty meta data test
	plmIdToApiMetaDataList[L"CLO_API_BLUE"] = apiMetaData;

	// 2. white
	color.R = 255;
	color.G = 255;
	color.B = 255;

	plmIdToNameList[L"CLO_API_WHITE"] = L"CLO_API_WHITE";
	plmIdToColorList[L"CLO_API_WHITE"] = color;

	apiMetaData = L""; // empty meta data test
	plmIdToApiMetaDataList[L"CLO_API_WHITE"] = apiMetaData;

	// add colorchip to color pallete
	UTILITY_API->AddColorSwatchW(plmIdToNameList, plmIdToColorList, plmIdToApiMetaDataList, swatchName);
}

void NewProject_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	UTILITY_API->NewProject();
}

void FabricFileMetaData_Sample()
{
	if (FABRIC_API == nullptr || UTILITY_API == nullptr)
		return;

	string baseFolder = getHomePath() + "fabric/";
	string testZFab = baseFolder + "test.zfab";
	wstring testZFabW(testZFab.begin(), testZFab.end());

	string metaData = FABRIC_API->GetAPIMetaDataFromFile(testZFab);
	UTILITY_API->DisplayMessageBox(metaData);

	wstring metaDataW = FABRIC_API->GetAPIMetaDataFromFileW(testZFabW);
	UTILITY_API->DisplayMessageBoxW(metaDataW);
}

void GetCLOFilePath_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	string executableFolderPath = UTILITY_API->GetCLOExecutableFolderPath(true); // path delimiter '/'
	UTILITY_API->DisplayMessageBox(executableFolderPath);

	wstring executableFolderPathW = UTILITY_API->GetCLOExecutableFolderPathW(false); // path delimiter '\\'
	UTILITY_API->DisplayMessageBoxW(executableFolderPathW);

	string assetFolderPathForCurrentVersion = UTILITY_API->GetCLOAssetFolderPath(false); // path delimiter '\\'
	UTILITY_API->DisplayMessageBox(assetFolderPathForCurrentVersion);

	wstring assetFolderPathForCurrentVersionW = UTILITY_API->GetCLOAssetFolderPathW(true); // path delimiter '/'
	UTILITY_API->DisplayMessageBoxW(assetFolderPathForCurrentVersionW);
}

void ExportTurntableImages_Sample()
{
	if (EXPORT_API == nullptr)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	EXPORT_API->ExportTurntableImages(baseFolder + "test.png", 12);
}

void ExportTurntableVideos_Sample()
{
	if (EXPORT_API == nullptr)
		return;

	string baseFolder = getHomePath() + "export_videos/";
	EXPORT_API->ExportTurntableVideo(baseFolder + "turntable_video_output.avi");
}

void ExportAnimationVideos_Sample()
{
	if (EXPORT_API == nullptr)
		return;

	string baseFolder = getHomePath() + "export_videos/";
	EXPORT_API->ExportAnimationVideo(baseFolder + "animation_video_output.avi");
}

void ReadWriteMetaDataFile_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	string baseFolder = getHomePath() + "test_metadata/";
	string filePath = baseFolder + "test_metadata_file.zprj";
	
	string sampleMetaData = "{\n"; // start element	
	sampleMetaData += "\"metaData1\": \"Merong\""; // itemId
	sampleMetaData += "\n}\n"; // end element

	string preVal = UTILITY_API->GetAPIMetaData(filePath);
	UTILITY_API->DisplayMessageBox(preVal);

	UTILITY_API->SetAPIMetaData(filePath, sampleMetaData);

	string val = UTILITY_API->GetAPIMetaData(filePath);
	UTILITY_API->DisplayMessageBox(val);
}

void ExportGLTF_Sample()
{
	if (!EXPORT_API)
		return;

	Marvelous::ImportExportOption options;
	options.bExportAvatar = false;
	options.bExportGarment = true;
	options.bSaveInZip = true;
	options.scale = 0.001f; // gltf scale

	// the other options are given as default. please refer to ImportExportOption class in ExportAPI.h

	vector<string> exportedFilePathList;
	string baseFolder = getHomePath() + "export_gltf/";
	exportedFilePathList = EXPORT_API->ExportGLTF(baseFolder + "test.gltf", options, false); // returns only a file path for a zipped file including GLTF and BIN files.

	for (auto& path : exportedFilePathList)
	{
		if (UTILITY_API)
			UTILITY_API->DisplayMessageBox(path);
	}
}

void SetWindowsTitle3D_Sample()
{
	wstring _title = L"CLO API Sample Windows 3D";
	if (UTILITY_API)
		UTILITY_API->Set3DWindowTitleW(_title);
}

void CopyColorway_Sample()
{
	if (UTILITY_API == nullptr)
		return;

	unsigned newColorwayIndex = UTILITY_API->CopyColorway(2);
	if (newColorwayIndex == 0)
		return;

	string newColorwayName = "Colorway By CLO API";
	UTILITY_API->SetColorwayName(newColorwayIndex, newColorwayName);

	UTILITY_API->RefreshColorwayDialog();
}

void ExportTechPackToStream_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	fprintf(stdout, "Start Export Tech Pack to Stream !! ========================== \n");

	string exportPath = UTILITY_API->GetCLOTemporaryFolderPath() + "test.json";
	string outputPath = EXPORT_API->ExportTechPackToStream(exportPath);

	fprintf(stdout, "========================== END of the TEST ========================== \n");
}

void ExportSingleColorwayRenderingImage_Sample()
{
	if (!EXPORT_API)
		return;

	unsigned int defaultIndex = 0;
	vector<string> outputPath = EXPORT_API->ExportSingleColorwayRenderingImage(defaultIndex);
}

void GetTotalRenderImagePaths_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	vector<string> outputPath = EXPORT_API->GetTotalRenderImagePaths();

	string resultPaths = "Total Render Image Paths :\n";
	for (const auto& path : outputPath)
	{
		resultPaths.append(path + "\n");
	}
	UTILITY_API->DisplayMessageBox(resultPaths);
}

void GetCurrentRenderImagePaths_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	vector<string> outputPath = EXPORT_API->GetCurrentRenderImagePaths();

	string resultPaths = "Current Render Image Paths :\n";
	for (const auto& path : outputPath)
	{
		resultPaths.append(path + "\n");
	}
	UTILITY_API->DisplayMessageBox(resultPaths);
}

void GetFileNameOnRenderingProperty_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	string resultMsg = EXPORT_API->GetFileNameOnRenderingProperty();
	UTILITY_API->DisplayMessageBox(resultMsg);
}

void GetColorwayRelatedInformation_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	string msg = "";
	unsigned int count = EXPORT_API->GetColorwayCount();
	msg.append("ColorWay count : " + to_string(count) + "\n");

	unsigned int currentIndex = EXPORT_API->GetCurrentColorwayIndex();
	msg.append("Current colorWay index : " + to_string(currentIndex) + "\n");
	
	
	vector<string> outputName = EXPORT_API->GetColorwayNameList();
	msg.append("Colorway name list : ");
	for (const auto& name : outputName)
	{
		msg.append(name + " ");
	}
	UTILITY_API->DisplayMessageBox(msg);
}

void GetSizeRelatedInformation_Sample()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	string msg = "";
	unsigned int count = EXPORT_API->GetSizeCount();
	msg.append("Size count : " + to_string(count) + "\n");

	unsigned int currentIndex = EXPORT_API->GetCurrentSizeIndex();
	msg.append("Current size index : " + to_string(currentIndex) + "\n");


	vector<string> outputName = EXPORT_API->GetSizeNameList();
	msg.append("Size name list : ");
	for (const auto& name : outputName)
	{
		msg.append(name + " ");
	}
	UTILITY_API->DisplayMessageBox(msg);
}

void GetFabricRelatedInformation_Sample()
{
	if (!FABRIC_API || !UTILITY_API)
		return;

	string msg = "";
	unsigned int count = FABRIC_API->GetFabricCount();
	msg.append("Fabric count : " + to_string(count) + "\n");

	unsigned int currentIndex = FABRIC_API->GetCurrentFabricIndex();
	msg.append("Current fabric index : " + to_string(currentIndex) + "\n");

	string fabricTextureName = FABRIC_API->GetFirstFabricTextureName();
	msg.append("First fabric texture name : " + fabricTextureName + "\n");

	int defaultPatternIndex = 0; // Get fabric index for pattern #0
	int patternFabricIndex = FABRIC_API->GetFabricIndexForPattern(defaultPatternIndex);
	msg.append("Fabric index for pattern : " + to_string(patternFabricIndex) + "\n");

	string defaultFabricName = "FABRIC 1";
	int fabricIndex = FABRIC_API->GetFabricIndex(defaultFabricName);
	msg.append("Fabric index : " + to_string(fabricIndex) + "\n");

	int defaultFabricIndex = 0;
	string fabricName = FABRIC_API->GetFabricName(defaultFabricIndex);
	msg.append("Fabric name : " + fabricName + "\n");

	int defaultColorwayIndex = 0;
	string colorwayFabricInfo = FABRIC_API->GetColorwayFabricInfo(defaultColorwayIndex, defaultFabricIndex);
	msg.append("Colorway fabric info : " + colorwayFabricInfo + "\n");

	UTILITY_API->DisplayMessageBox(msg);
}

void ChangeFabricWithJson_Sample()
{
	if (!FABRIC_API || !UTILITY_API)
		return;

	int defaultFabricIndex = 0;

	string baseFolder = getHomePath() + "fabric/";
	string testJsonPath = baseFolder + "fabric_test.json";
	bool bResult = FABRIC_API->ChangeFabricWithJson(defaultFabricIndex, testJsonPath);

	if (bResult)
		UTILITY_API->DisplayMessageBox("Failed to change fabric with JSON.");
	else
		UTILITY_API->DisplayMessageBox("Complete to change fabric with JSON.");
}

void AssignFabricToPattern_Sample()
{
	if (!FABRIC_API || !UTILITY_API)
		return;

	// Assign Fabric #0 to the pattern #0
	int defaultFabricIndex = 0;
	int defaultPatternIndex = 0;
	bool bResult = FABRIC_API->AssignFabricToPattern(defaultFabricIndex, defaultPatternIndex);

	if(bResult)
		UTILITY_API->DisplayMessageBox("Complete to assign fabric to pattern.");		
	else
		UTILITY_API->DisplayMessageBox("Failed to assign fabric to pattern.");
}

void ImportZprj_Sample()
{
	if (!IMPORT_API)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	string filePath = baseFolder + "test.zprj"; //must assign correct file path

	Marvelous::ImportZPRJOption option;
	IMPORT_API->ImportZprj(filePath, option);
}

void ImportFile_Sample()
{
	if (!IMPORT_API)
		return;

	string baseFolder = getHomePath() + "Zpac/";
	string filePath = baseFolder + "test.zprj"; //must assign correct file path

	IMPORT_API->ImportFile(filePath);
}

void ExportZpac_Test()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	string exportPath = EXPORT_API->ExportZPac();

	string msg = "Export ZPac Complete: " + exportPath;
	UTILITY_API->DisplayMessageBox(msg);
}

void GetAvatarCount_Test()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	unsigned int avatarCnt = EXPORT_API->GetAvatarCount();

	string msg = "Avatar Count : " + to_string(avatarCnt);
	UTILITY_API->DisplayMessageBox(msg);
}

void GetAvatarNameList_Test()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	vector<string> avatarNameList = EXPORT_API->GetAvatarNameList();

	string msg = "Avatar Name List : ";
	for (size_t i = 0; i < avatarNameList.size(); ++i)
		msg = msg + avatarNameList[i] + "\n";

	UTILITY_API->DisplayMessageBox(msg);
}

void GetAvatarGenderList_Test()
{
	if (!EXPORT_API || !UTILITY_API)
		return;

	vector<int> avatarGenderList = EXPORT_API->GetAvatarGenderList();

	string msg = "Avatar Gender List : ";
	for (size_t i = 0; i < avatarGenderList.size(); ++i)
	{
		if (avatarGenderList[i] == 0)
			msg = msg + "male" + "\n";
		else if (avatarGenderList[i] == 1)
			msg = msg + "female" + "\n";
		else
			msg = msg + "unknown" + "\n";
	}

	UTILITY_API->DisplayMessageBox(msg);
}

void GetPatternIndex_Test()
{
	// prior to calling this function.
	// please set the appropriate pattern name to "Test API Pattern" in the CLO software
	if (!PATTERN_API || !UTILITY_API)
		return;

	string patternName = "Test API Pattern";
	unsigned int patternIndex = PATTERN_API->GetPatternIndex(patternName);

	string msg = "Index of Test API Pattern : " + to_string(patternIndex);
	UTILITY_API->DisplayMessageBox(msg);
}

void GetPatternCount_Test()
{
	if (!PATTERN_API || !UTILITY_API)
		return;

	unsigned int patternCnt = PATTERN_API->GetPatternCount();

	string msg = "Pattern Count : " + to_string(patternCnt);
	UTILITY_API->DisplayMessageBox(msg);
}

void GetMajorVersion_Test()
{
	if (!UTILITY_API)
		return;

	unsigned int majorVer = UTILITY_API->GetMajorVersion();

	string msg = "Major Version of CLO : " + to_string(majorVer);
	UTILITY_API->DisplayMessageBox(msg);
}

void GetMinorVersion_Test()
{
	if (!UTILITY_API)
		return;

	unsigned int minorVer = UTILITY_API->GetMinorVersion();

	string msg = "Minor Version of CLO : " + to_string(minorVer);
	UTILITY_API->DisplayMessageBox(msg);
}

void GetPatchVersion_Test()
{
	if (!UTILITY_API)
		return;

	unsigned int patchVer = UTILITY_API->GetPatchVersion();

	string msg = "Patch Version of CLO : " + to_string(patchVer);
	UTILITY_API->DisplayMessageBox(msg);
}

void ExportGLB_Sample()
{
	if (!EXPORT_API)
		return;

	Marvelous::ImportExportOption options;
	options.bExportAvatar = false;
	options.bExportGarment = true;
	options.bSaveInZip = false;
	options.scale = 0.001f; // same as gltf scale

	// the other options are given as default. please refer to ImportExportOption class in ExportAPI.h

	vector<string> exportedFilePathList;
	string baseFolder = getHomePath() + "export_glb/";
	exportedFilePathList = EXPORT_API->ExportGLB(baseFolder + "test.glb", options); // returns only a file path for GLB file 

	for (auto& path : exportedFilePathList)
	{
		if (UTILITY_API)
			UTILITY_API->DisplayMessageBox(path);
	}
}

extern CLO_PLUGIN_SPECIFIER void DoFunction()
{
#if USE_EXPORT_ZPRJ_SAMPLE
	ExportZprjSample();
#endif

#if USE_RENDERINGIMAGE_SAMPLE
	ExportRenderingImage_Sample();
#endif

#if USE_EXPORT_TECHPACK_SAMPLE
	ExportTechPack_Sample();
#endif

#if USE_EXPORT_OBJ_SAMPLE
	ExportOBJ_Sample();
#endif

#if USE_FABRIC_SAMPLE
	ExportFabric_Sample();
	ImportFabric_Sample();
	DeleteFabric_Sample();
	FabricMetaData_Sample();
#endif

#if USE_PROGRESSBAR_SAMPLE
	ProgressBar_Sample();
#endif

#if USE_EXPORT_SIMULATION_SAMPLE
	ExportSimulation_Sample();
#endif

#if USE_GET_INFORMATIONS_SAMPLE
	GetInformations_Sample();
#endif

#if USE_GET_CUSTOM_VIEW_SAMPLE
	GetCustomView_Sample();
	GetCustomViewWithZcmrTest();
#endif

#if USE_COLORWAY_NAME_SAMPLE
	ColorwayName_Sample();
#endif

#if USE_REST_API_TEST
	HttpGetTest(); // to test GetByteArrayFromStream() function
	string baseFolder = getHomePath() + "Zpac/";
	UploadToCLOSET(baseFolder + "test.zpac"); // to test CallRESTPostWithMultipartFormData() 
#endif

#if USE_UNICODE_FUNCTION_TEST
	UnicodeFunctionsTest();
#endif

#if USE_ADD_COLORCHIP_TEST
	AddColorChip_Sample();
#endif

#if USE_NEW_PROJECT_TEST
	NewProject_Sample();
#endif

#if USE_FABRIC_FILE_METADATA_TEST
	FabricFileMetaData_Sample();
#endif

#if USE_GET_CLO_FILE_PATH_TEST
	GetCLOFilePath_Sample();
#endif

#if USE_EXPORT_TURNTABLE_IMAGES
	ExportTurntableImages_Sample();
#endif

#if USE_EXPORT_GLTF_TEST
	ExportGLTF_Sample();
#endif

#if USE_EXPORT_TURNTABLE_VIDEO
	ExportTurntableVideos_Sample();
#endif

#if USE_EXPORT_ANIMATION_VIDEO
	ExportAnimationVideos_Sample();
#endif

#if USE_READ_WRITE_METADATA_FILE //still developing
	ReadWriteMetaDataFile_Sample();
#endif

#if	USE_SET_WINDOWS_TITLE_3D_TEST
	SetWindowsTitle3D_Sample();
#endif

#if USE_COPY_COLORWAY_TEST
	CopyColorway_Sample();
#endif

#if USE_GARMENT_INFO_TEST
	ExportGarmentInformation_Sample();
	ImportGarmentInformation_Sample();
#endif

#if USE_GARMENT_INFO_CONFIG_TEST
	ExportGarmentInformationConfigData_Sample();
	ImportGarmentInformationConfigData_Sample();
#endif

#if USE_EXPORT_TECHPACK_TO_STREAM_TEST
	ExportTechPackToStream_Sample();
#endif

#if USE_EXPORT_THUMBNAIL3D_TEST
	ExportThumbnail3D_Sample();
#endif

#if USE_EXPORT_SNAPSHOT3D_TEST
	ExportSnapshot3D_Sample();
#endif

#if USE_EXPORT_SINGLE_COLORWAY_RENDERING_IMAGE_TEST
	ExportSingleColorwayRenderingImage_Sample();
#endif

#if USE_GET_RENDER_IMAGE_RELATED_PATHS_TEST
	GetTotalRenderImagePaths_Sample();
	GetCurrentRenderImagePaths_Sample();
#endif

#if USE_GET_FILE_NAME_ON_RENDERING_PROPERTY_TEST
	GetFileNameOnRenderingProperty_Sample();
#endif

#if USE_GET_COLORWAY_RELATED_INFORMATION_TEST
	GetColorwayRelatedInformation_Sample();
#endif

#if USE_GET_SIZE_RELATED_INFORMATION_TEST
	GetSizeRelatedInformation_Sample();
#endif

#if USE_GET_FABRIC_RELATED_INFORMATION_TEST
	GetFabricRelatedInformation_Sample();
#endif

#if USE_CHANGE_FABRIC_WITH_JSON_TEST
	ChangeFabricWithJson_Sample();
#endif

#if USE_ASSIGN_FABRIC_TO_PATTERN_TEST
	AssignFabricToPattern_Sample();
#endif

#if USE_IMPORT_ZPRJ_SAMPLE
	ImportZprj_Sample();
#endif

#if USE_IMPORT_FILE_SAMPLE
	ImportFile_Sample();
#endif

#if USE_EXPORT_ZPAC_TEST
	ExportZpac_Test();
#endif

#if USE_AVATAR_RELATED_API_TEST
	GetAvatarCount_Test();
	GetAvatarNameList_Test();
	GetAvatarGenderList_Test();
#endif

#if USE_PATTERN_RELATED_API_TEST
	GetPatternIndex_Test();
	GetPatternCount_Test();
#endif

#if USE_VERSION_CHECK_API_TEST
	GetMajorVersion_Test();
	GetMinorVersion_Test();
	GetPatchVersion_Test();
#endif

#if USE_EXPORT_GLB_TEST
	ExportGLB_Sample();
#endif
}

extern CLO_PLUGIN_SPECIFIER void DoFunctionAfterLoadingCLOFile(const char* fileExtenstion)
{
	if (UTILITY_API != nullptr)
		UTILITY_API->DisplayMessageBox("DoFunctionAferLoadingProject starts... for file type -  " + string(fileExtenstion));
}

extern CLO_PLUGIN_SPECIFIER const char* GetActionName()
{
	const char* actionName = "Plugin Sample";

#if USE_RENDERINGIMAGE_SAMPLE
	actionName = "Rendering Image Sample Plugin";
#endif

#if USE_EXPORT_TECHPACK_SAMPLE
	actionName = "Export Techpack Sample Plugin";
#endif

#if USE_EXPORT_OBJ_SAMPLE
	actionName = "Export Obj Sample Plugin";
#endif

#if USE_EXPORT_ZPRJ_SAMPLE
	actionName = "Export Zprj Sample Plugin";
#endif

#if USE_FABRIC_SAMPLE
	actionName = "Plugin with using Fabric API Sample";
#endif

#if USE_PROGRESSBAR_SAMPLE
	actionName = "Progress Bar Sample Plugin";
#endif

#if USE_GET_INFORMATIONS_SAMPLE
	actionName = "Get Information Sample Plugin";
#endif

#if USE_GET_CUSTOM_VIEW_SAMPLE
	actionName = "Get Custom View Sample Plugin";
#endif

#if USE_COLORWAY_NAME_SAMPLE
	actionName = "Colorway Name Sample Plugin";
#endif

#if USE_REST_API_TEST
	actionName = "Rest API Sample Plugin";
#endif

#if USE_UNICODE_FUNCTION_TEST
	actionName = "API with wstring Sample Plugin";
#endif

#if USE_ADD_COLORCHIP_TEST
	actionName = "Add Colorchip Sample Plugin";
#endif

#if USE_NEW_PROJECT_TEST
	actionName = "New project Sample Plugin";
#endif

#if USE_FABRIC_FILE_METADATA_TEST
	actionName = "Fabric metadata Sample Plugin";
#endif

#if USE_GET_CLO_FILE_PATH_TEST
	actionName = "CLO file path Sample Plugin";
#endif

#if USE_EXPORT_TURNTABLE_IMAGES
	actionName = "Export Turntable Images Sample Plugin";
#endif

#if USE_EXPORT_GLTF_TEST
	actionName = "Export GLTF Sample Plugin";
#endif

#if USE_EXPORT_TURNTABLE_VIDEO
	actionName = "Export Turntable Video Sample Plugin";
#endif

#if USE_READ_WRITE_METADATA_FILE
	actionName = "Metadata from file Sample Plugin";
#endif

#if USE_SET_WINDOWS_TITLE_3D_TEST
	actionName = "Set 3D Windows Title Sample Plugin";
#endif

#if USE_COPY_COLORWAY_TEST
	actionName = "Copy Colorway Sample Plugin";
#endif

#if USE_GARMENT_INFO_TEST
	actionName = "Garment Information Sample Plugin";
#endif

#if USE_GARMENT_INFO_CONFIG_TEST
	actionName = "Garment Information Config Data Plugin";
#endif

#if USE_EXPORT_ANIMATION_VIDEO
	actionName = "Export Animation Video Sample Plugin";
#endif

#if USE_IMPORT_ZPRJ_SAMPLE
	actionName = "Import Zprj Sample Plugin";
#endif

#if USE_IMPORT_FILE_SAMPLE
	actionName = "Import File Sample Plugin";
#endif

#if USE_EXPORT_ZPAC_TEST
	actionName = "Export Zpac Test";
#endif

#if USE_AVATAR_RELATED_API_TEST
	actionName = "Avatar Related API calls Test";
#endif

#if USE_EXPORT_SIMULATION_SAMPLE
	actionName = "Export Simulation Sample Test";
#endif

#if USE_EXPORT_TECHPACK_TO_STREAM_TEST
	actionName = "Export Techpack to Stream Test";
#endif

#if USE_EXPORT_THUMBNAIL3D_TEST
	actionName = "Export Thumbnail3D Test";
#endif

#if USE_EXPORT_SNAPSHOT3D_TEST
	actionName = "Export Snapshot3D Test";
#endif

#if USE_EXPORT_SINGLE_COLORWAY_RENDERING_IMAGE_TEST
	actionName = "Export Single Colorway Rendering Image Test";
#endif

#if USE_GET_RENDER_IMAGE_RELATED_PATHS_TEST
	actionName = "Get Render Image Related Path Test";
#endif

#if USE_GET_FILE_NAME_ON_RENDERING_PROPERTY_TEST
	actionName = "Get File Name on Rendering Property Test";
#endif

#if USE_GET_COLORWAY_RELATED_INFORMATION_TEST
	actionName = "Get Colorway Related Information Test";
#endif

#if USE_GET_SIZE_RELATED_INFORMATION_TEST
	actionName = "Get Size Related Information Test";
#endif

#if USE_GET_FABRIC_RELATED_INFORMATION_TEST
	actionName = "Get Fabric Related Information Test";
#endif

#if USE_CHANGE_FABRIC_WITH_JSON_TEST
	actionName = "Change Fabric with Json Test";
#endif

#if USE_ASSIGN_FABRIC_TO_PATTERN_TEST
	actionName = "Assign Fabric to Pattern Test";
#endif

#if USE_EXPORT_GLB_TEST
	actionName = "Export GLB Sample Plugin";
#endif	

	return actionName;
}

extern CLO_PLUGIN_SPECIFIER const char* GetObjectNameTreeToAddAction()
{
	const char* objetNameTree = "menu_Setting / menuPlug_In";

	return objetNameTree;
}

extern CLO_PLUGIN_SPECIFIER int GetPositionIndexToAddAction()
{
	return 1; // 0: Above, 1: below (default = 0)
}
