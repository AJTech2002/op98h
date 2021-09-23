#pragma once

#include <map>
#include <string>

/**
	@file CloApiData.h
	@brief Pre defined Enumerator and option classes / structures
*/
namespace Marvelous
{
	/// @enum EXPORTFILETYPE
	/// @brief Do Not Use this in CLO API/SDK side. This enumerator is set in CLO software module automatically.
	enum EXPORTFILETYPE
	{
		EXPORT_OBJ_FILE,
		EXPORT_FBX_FILE,
		EXPORT_LXO_FILE,
		EXPORT_GLTF_FILE,
		EXPORT_GLB_FILE
	};

	/// @enum TEXTURE_SAVE_METHOD
	/// @brief Do Not Use this in CLO API/SDK side. This enumerator represents the "Texture" comobobox index for "Export Fbx" feature
	enum TEXTURE_SAVE_METHOD
	{
		RELATIVE_PATH,
		ABSOLUTE_PATH,
		SAVE_WITH_TEXTURE,
		EMBED_MEDIA
	};

	/// @enum WELD_TYPE
	/// @brief Weld type to export meshes. WELDED - merge meshes on seamlines, UNWELDED - as-is
	enum WELD_TYPE
	{
		FULLY_UNWELDED = 0, /// UNWELDED for all seamlines
		DEFAULT_WELDED = 1, /// deprecated, but DO NOT REMOVE.
		FULLY_WELDED = 2,	/// WELDED for all seamlines
		SELECTED_WELDED = 3 /// WELDED for selected seamlines
	};

	/// @class ImportExportOption
	/// @brief Options for Export OBJ and Export GLTF as parameters without dialogs in CLO API
	class ImportExportOption
	{
	public:

		/////////////////////////
		// Export OBJ / GLTF
		bool bExportGarment; /// true : Export Garment (Cloth Meshes)
		bool bExportAvatar;  /// true : Export Avatar (Avatar Meshes)
		bool bExportSceneProp; /// true : Export Scene & Prop (SceneProp Meshes)

		bool bSingleObject;  /// true : OBJ single object, false : OBJ multiple object
		WELD_TYPE weldType;  /// FULLY_UNWELDED : unweld, FULLY_WELDED : weld, SELECTED_WELDED : Weld selected patterns in workspace, DEFAULT_WELDED : Do not use!!!

		bool bThin;          /// if true, export the garment as thin mesh. Otherwise, export it as thick mesh.

		bool bUnifiedUVCoordinates;   	  /// flag for Unified UV Coordinates
		bool bCreateUnifiedTexture;   	  /// flag for Unified Texture option - if bUnifiedUVCoordinates is true, this value should be set in true as well.
		float unifiedTextureSize;     	  /// true: (In case bCreateUnifiedTexture is true) The size of unified texture (pixels). Texture will be created in square.
		float unifiedTextureFillSeam; 	  /// true: (In case bCreateUnifiedTexture is true) Fill texture seam in millimeters(mm)
		float unifiedTextureBakeMargin;   /// true: (In case bCreateUnifiedTexture is true) The margin of the baked texture in the image canvas
		bool unifiedTextureBakeRelateive; /// true: (In case bCreateUnifiedTexture is true)

		bool bUnifiedDiffuseMap;		  /// false: (In case bCreateUnifiedTexture is true) export diffuse map baked in the unified uv
		bool bUnifiedNormalMap; 		  /// false: (In case bCreateUnifiedTexture is true) export normal map baked in the unified uv
		bool bUnifiedMetalnessMap;		  /// false: (In case bCreateUnifiedTexture is true) export metalness map baked in the unified uv
		bool bUnifiedRoughnessMap;		  /// false: (In case bCreateUnifiedTexture is true) export roughness map baked in the unified uv
		bool bUnifiedOpacityMap;		  /// false: (In case bCreateUnifiedTexture is true) export opacity map baked in the unified uv
		
		bool bIncludeHiddenObject; 		  /// if true, export all the pattern meshes include 'hidden pattern meshes on 3D' to OBJ
		bool bIncludeInnerShape;		  /// If true, export geometries of internal lines to ease the picking the internal lines in external modeling tools such as Maya and 3ds Max.

		float scale; 					  /// how to scale the object created in CLO when exporting. The default unit of CLO is millimeters for obj/fbx(mm) and gltf(m)
					 					  /// use 0.001 for gltf in default 

		int axisX; /// the index of the axis which the X axis will be converted to. If you don't want axis conversion, set this value as "0"
		int axisY; /// the index of the axis which the Y axis will be converted to. If you don't want axis conversion, set this value as "1"
		int axisZ; /// the index of the axis which the Z axis will be converted to. If you don't want axis conversion, set this value as "2"
		bool bInvertX; /// invert the axis which the X axis will be converted to
		bool bInvertY; /// invert the axis which the Y axis will be converted to
		bool bInvertZ; /// invert the axis which the Z axis will be converted to

		bool bSaveColorWays; /// if true, export obj for all the colorways per bSaveColorWaysMultipleUVs value.
		bool bSaveColorWaysMultipleUVs; /// when bSaveColorWays is true, if bSaveColorWaysMultipleUVs is true: export multiple objs and mtls for all the colorway respectively.  if false: export single obj and multiple mtl files for all the colorway respectively.)
		//bool bSaveColorWaysSingleUV; /// if true, export single obj and multiple mtl files for all the colorway respectively.

		bool bSaveInZip; 		/// If true, export as a zipped file with textures. It will output a single zipped file(.zip), not separated files.
		bool bDiffuseColorCombined; /// if true, the texture will be exported after being combined with diffuse color	
		bool bExcludeAmbient; /// if true, exclude ambient map and color in MTL files.
		bool bOpacityMap; 	  /// if true, generate an opacity map by extracting alpha channel from diffuse map
		bool bMetaData;   	  /// export meta data
						  	  // end of Export OBJ
						  	  /////////////////////////

						      /////////////////////////
						      //	for glTF export only
		bool bEmbedded;       /// for embedded-gltf export option
		bool bExportLight;    /// export light information in gltf

					 	  	  /////////////////////////
					 	  	  //	for FBX export only (These options are not available on CLO API)
		bool bAscii; 		  /// fbx ascii or binary
		int  fbxSdkVersion;   /// 0 : 2016, 1: 2014/2015, 2: 2013, 3 : 2012
		TEXTURE_SAVE_METHOD textureSaveMethod; /// 0: Relative Path, 1: Absolute Path, 2: Save with textures(in Zip file), 3: Embed Media
		bool bIncludeSceneProp;

		/////////////////////////
		// for vertex cache only (These options are not available on CLO API)
		float timeScale;  	 /// The index of the axis which the X axis will be converted to. If you don't want axis conversion, set this value as "0"
		unsigned int fps; 	 /// FPS to import/export vertex cache 

	  	/////////////////////////
	  	// for Alembic only (These options are not available on CLO API)
		float anim_step;
		bool bExportShutterSpeed;
		float shutter_low;
		float shutter_high;
		bool m_bExportStrainColorMap;
		bool m_bExportStressColorMap;

		/////////////////////////
		// for ZBrush, Alembic only (These options are not available on CLO API)
		bool bIncludeAvatarShape;

		ImportExportOption()
		{
			bExportGarment = true;
			bExportAvatar = true;
			bExportSceneProp = false;

			bSingleObject = false;
			weldType = FULLY_UNWELDED;

			bThin = true;

			bUnifiedUVCoordinates = false;
			bCreateUnifiedTexture = false;
			unifiedTextureSize = 2048.0f;
			unifiedTextureFillSeam = 1.0f;
			bUnifiedDiffuseMap = false;
			bUnifiedNormalMap = false;
			bUnifiedMetalnessMap = false;
			bUnifiedRoughnessMap = false;
			bUnifiedOpacityMap = false;

			unifiedTextureBakeRelateive = true;
			unifiedTextureBakeMargin = 0.01f;

			bIncludeHiddenObject = false;
			bIncludeInnerShape = false;

			scale = 1.0f;

			axisX = 0;
			axisY = 1;
			axisZ = 2;
			bInvertX = false;
			bInvertY = false;
			bInvertZ = false;

			bSaveColorWays = false;
			bSaveColorWaysMultipleUVs = true;

			bSaveInZip = false;
			bDiffuseColorCombined = false;
			bExcludeAmbient = false;
			bOpacityMap = false;
			bMetaData = false;

			bEmbedded = false; 
			bExportLight = false;

			////
			bAscii = false;
			fbxSdkVersion = 0;
			textureSaveMethod = RELATIVE_PATH;

			anim_step = 1.0f;
			bExportShutterSpeed = false;
			shutter_low = 0.0f;
			shutter_high = 0.0f;
			m_bExportStrainColorMap = false;
			m_bExportStressColorMap = false;

			bIncludeAvatarShape = true;
			bIncludeSceneProp = true;
			//
			timeScale = 1.0f;
			fps = 30;


		}
		virtual ~ImportExportOption()
		{}
	};

	/// @enum CLO_API_UNIT
	/// @brief Unit types 
	enum CLO_API_UNIT
	{
		CLO_API_MILIMETER,  /// milimeter
		CLO_API_CENTIMETER, /// centimeter
		CLO_API_INCH,		/// inch
		CLO_API_METER,		/// meter
		CLO_API_FEET		/// feet
	};

	/// @class ImportZPRJOption
	/// @brief Options for ImportZPRJ as parameters without dialogs in CLO API
	struct ImportZPRJOption 
	{
		bool bAppend;					/// if true, append the project file to the current loaded project
										/// if false, overwrite/replace the project file in the current loaded project

		bool bLoadGarment;				/// if true, open/add Garment inside the zprj file into the current loaded project
		bool bLoadAvatar;				/// if true, open/add Avatar inside the zprj file into the current loaded project

		float translationValueX;		/// set x-offet value per current patterns in 2D Window for Patterns (left - right)
										/// set x-offset value per the position-value inside the zprj file in 3D Window for Avatar/Garment (left - right)
		float translationValueY;		/// set y-offet value per current patterns in 2D Window for Patterns (up - down)
										/// set y-offset value per the position-value inside the zprj file in 3D Window for Avatar/Garment
		float translationValueZ;		/// set z-offset value per the position-value inside the zprj file in 3D Window for Avatar/Garment (monitor - user)

		CLO_API_UNIT translationUnit;	/// translationUnit - 0: Milimeter, 1: Centimeter, 2: Inch, 3: Meter, 4: Feet

		// initialize
		ImportZPRJOption() : bAppend(false),
			bLoadGarment(true),
			bLoadAvatar(true),
			translationValueX(0.0f),
			translationValueY(0.0f),
			translationValueZ(0.0f),
			translationUnit(CLO_API_MILIMETER) {}
	};

	/// @class ExportDxfOption
	/// @brief Options for ExportDxf as parameters without dialogs in CLO API
	struct ExportDxfOption
	{
		bool m_bSwapOutLine;			    /// if true, swap the boundary line with sew line
		bool m_bDuplicateNotch;			    /// if true, remove duplicate notches
		bool m_bCheckedConvertCtoS;		    /// if true, convert curve points to straight points to export
		bool m_bExportWithoutGrading;	    /// if true, export without grading information
		bool m_bOptimizeCurvePoints;	    /// if true, optimize curve points with removing the points close to some points
		bool m_bExportWithoutBaselines;     /// if true, export only out lines without base lines
		unsigned int m_ExportDXFFormatType; /// 0: DXF-AAMA, 1: DXF-ASTM, 2: Gerber(DXF-AAMA)
		unsigned int m_ExportBBType;		/// 1: Use Bounding box covering all the patterns, 2: use Bounding Box for each pattern
		float m_fScale;						/// scale variables 
		float m_RotateAngle;				/// Rotation angle for patterns
		bool m_bMetric;						/// Measurement unit shown on DXF, true: Metric, false: English

		ExportDxfOption() : m_bSwapOutLine(false),
			m_bCheckedConvertCtoS(false),
			m_bExportWithoutGrading(false),
			m_bOptimizeCurvePoints(false),
			m_bExportWithoutBaselines(false),
			m_ExportDXFFormatType(1),
			m_ExportBBType(1),
			m_fScale(1.0f),
			m_RotateAngle(0.0f),
			m_bMetric(true) {}
	};

	/// @enum ExportTechPackType
	/// @brief Export Techpack types
	enum ExportTechPackType
	{
		CLO_TECH_PACK,		/// techpack used in CLO
		CLO_SET_TECH_PACK,	/// techpack used in CLOSET
		CLO_SET_ZREST, 		/// techpack used in ZREST (used in CLOSET)
		CLO_API_TECH_PACK,	/// techpack for CLO API (excludes the internal values used in CLO Virtual Fashion)
		CLO_DUMMY			/// n/a
	};

	/// @struct ExportTechpackOption
	/// @brief Options for Export Techpack as parameters without dialogs in CLO API
	struct ExportTechpackOption
	{
		bool m_bSaveZpac;										/// if true, save garment as a (project name).zpac file and describe the path on the techpack json (CLO API only)
		bool m_bSaveZprj;										/// if true, save project as a (project name).zprj file and describe the path on the techpack json (CLO API only)

		bool m_bCaptureSceneThumbnailWithoutAvatar;				/// if true, capture the thumbnail images as image files and describe the paths on the techpack json
		bool m_bCaptureSceneThumbnailWithMark;					/// if true, capture the thumbnail images with markers as image files and describe the paths on the techpack json (CLO API and CLOSET)
		bool m_bCaptureSceneThumbnailWithAvatar;				/// if true, capture the thumbnail images with avatars for all the colorways and describe the paths on the techpack json

		bool m_bCaptureItemThumbnail;							/// if true, capture thumbnail for pattern piecese (for CLO API and Techpack Image)
		bool m_bCapturePatternLayoutThumbnail;					/// if true, capture thumbnail for pattern layout (for CLO API and Techpack Image)
		bool m_bCapturePatternLayoutThumbnailWithFabricMark;	/// if true, capture thumbnail for pattern layout with fabric marks (for CLO API and Techpack Image)
		bool m_bCapturePatternLayoutThumbnailWithTrimMark;		/// if true, capture thumbnail for pattern layout with trim marks (for CLO API and Techpack Image)

		bool m_bExportTextures;									/// if true, export all the textures as image files and describe the paths on the techpack json (CLO API only)
		bool m_bUseAverageColor;								/// if true, calculate average color for the image used in materials and show the values in techpack json
		
		bool m_bShowModalProgressBar;						    /// if true, a Modal progress bar will appear to show progress in CLO Software

		std::map<unsigned int, bool> m_ShowBaseLineFor3DCapturePerColorway;  /// map(colorway index, show/hide flag) for Base Line while capturing 3D
		std::string m_AuthenticationKeyForAPI;						/// For companies to use extended functionalies in CLO API/SDK

		ExportTechPackType m_ExportType;					    /// 0: CLO_TECH_PACK, 1: CLO_SET_TECH_PACK, 2: CLO_SET_ZREST, 3: CLO_API_TECH_PACK, 4: CLO_DUMMY

		ExportTechpackOption()
		{
			m_bSaveZpac = true;
			m_bSaveZprj = true;
			m_bCaptureSceneThumbnailWithoutAvatar = true;
			m_bCaptureSceneThumbnailWithMark = true;
			m_bCaptureSceneThumbnailWithAvatar = true;
			m_bExportTextures = true;
			m_bCaptureItemThumbnail = true;
			m_bCapturePatternLayoutThumbnail = true;
			m_bCapturePatternLayoutThumbnailWithFabricMark = true;
			m_bCapturePatternLayoutThumbnailWithTrimMark = true;
			m_bUseAverageColor = true;
			m_bShowModalProgressBar = true;

			m_ShowBaseLineFor3DCapturePerColorway.clear();

			m_ExportType = CLO_API_TECH_PACK;
		}

		ExportTechpackOption(ExportTechPackType type)
		{
			if (type == CLO_TECH_PACK || type == CLO_API_TECH_PACK)
			{
				m_bSaveZpac = true;
				m_bSaveZprj = true;
				m_bCaptureSceneThumbnailWithoutAvatar = true;
				m_bCaptureSceneThumbnailWithMark = true;
				m_bCaptureSceneThumbnailWithAvatar = true;
				m_bExportTextures = true;
				m_bCaptureItemThumbnail = true;
				m_bCapturePatternLayoutThumbnail = true;
				m_bCapturePatternLayoutThumbnailWithFabricMark = true;
				m_bCapturePatternLayoutThumbnailWithTrimMark = true;
				m_bUseAverageColor = true;
			}
			else if (type == CLO_SET_TECH_PACK)
			{
				m_bSaveZpac = false;
				m_bSaveZprj = false;
				m_bCaptureSceneThumbnailWithoutAvatar = true;
				m_bCaptureSceneThumbnailWithMark = true;
				m_bCaptureSceneThumbnailWithAvatar = true;
				m_bExportTextures = false; // fabric의 texture는 내보낼 필요 없다.
				m_bCaptureItemThumbnail = true;
				m_bCapturePatternLayoutThumbnail = true;
				m_bCapturePatternLayoutThumbnailWithFabricMark = true;
				m_bCapturePatternLayoutThumbnailWithTrimMark = true;
				m_bUseAverageColor = true;
			}
			else if(type == CLO_SET_ZREST)
			{
				m_bSaveZpac = false;
				m_bSaveZprj = false;
				m_bCaptureSceneThumbnailWithoutAvatar = true;
				m_bCaptureSceneThumbnailWithMark = false;
				m_bCaptureSceneThumbnailWithAvatar = true;
				m_bExportTextures = false;
				m_bCaptureItemThumbnail = false;
				m_bCapturePatternLayoutThumbnail = false;
				m_bCapturePatternLayoutThumbnailWithFabricMark = false;
				m_bCapturePatternLayoutThumbnailWithTrimMark = false;
				m_bUseAverageColor = true;
			}
			else
			{
				m_bSaveZpac = false;
				m_bSaveZprj = false;
				m_bCaptureSceneThumbnailWithoutAvatar = false;
				m_bCaptureSceneThumbnailWithMark = false;
				m_bCaptureSceneThumbnailWithAvatar = false;
				m_bExportTextures = false;
				m_bCaptureItemThumbnail = false;
				m_bCapturePatternLayoutThumbnail = false;
				m_bCapturePatternLayoutThumbnailWithFabricMark = false;
				m_bCapturePatternLayoutThumbnailWithTrimMark = false;
				m_bUseAverageColor = false;
			}

			m_ShowBaseLineFor3DCapturePerColorway.clear();

			m_ExportType = type;
		}
	};

	/// @struct CloApiRgb
	/// @brief RGB Values structure for Color related api calls in CLO API
	struct CloApiRgb
	{
		int R; //Red: 0 ~ 255
		int G; //Green: 0 ~ 255
		int B; //Blue: 0 ~ 255

		CloApiRgb() :R(0), G(0), B(0) {}
	};

	/// @enum RenderColorwayType
	/// @brief Colorway Type for ExportRenderingImage in CLO API
	enum RenderColorwayType
	{
		SINGLE,			/// Export Rendering Image for only the current colorway
		ALL,			/// Export Rendering Image for all the colorways
		USER_DEFINED	/// Export Rendering Image per the current setting in the colorway type
	};
}
