#pragma once

#include "Win32App.h"
#include "DXSampleHelper.h"

class DXSample
{
	std::wstring m_assetsPath;
	std::wstring m_title;

public:
	DXSample(uint32_t width, uint32_t height, std::wstring name);
	virtual ~DXSample();

	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy() = 0;

	virtual void OnKeyDown(UINT8) {}
	virtual void OnKeyUp(UINT8) {}

	uint32_t GetWidth() const { return m_width; }
	uint32_t GetHeight() const { return m_height; }
	const WCHAR* GetTitle() const { return m_title.c_str(); }

	void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);

protected:
	std::wstring GetAssetFullPath(LPCWSTR assetName);

	void GetHardwareAdapter(
		_In_ IDXGIFactory1* factory,
		_Outptr_result_maybenull_ IDXGIAdapter1** adapter,
		bool requestHighPerformanceAdapter = false);

	void SetCustomWindowText(LPCWSTR text);

	uint32_t m_width;
	uint32_t m_height;
	float m_aspectRatio;

	bool m_useWarpDevice{ false };
	bool fullscreen{ false };
	bool vsync{ true };
	bool tearing{ false };
};