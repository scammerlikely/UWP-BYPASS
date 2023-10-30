
// Call Critisal_CHECKVERSION() from your Critisal.cpp files to verify that the data structures your files are using are matching the ones Critisal.cpp is using.
//-----------------------------------------------------------------------------

#pragma once

//---- Define assertion handler. Defaults to calling assert().
// If your macro uses multiple statements, make sure is enclosed in a 'do { .. } while (0)' block so it can be used as a single statement.
//#define Critisal_IM_ASSERT(_EXPR)  MyAssert(_EXPR)
//#define Critisal_IM_ASSERT(_EXPR)  ((void)(_EXPR))     // Disable asserts

//---- Define attributes of all API symbols declarations, e.g. for DLL under Windows
// Using Dear ImGui via a shared library is not recommended, because of function call overhead and because we don't guarantee backward nor forward ABI compatibility.
// DLL users: heaps and globals are not shared across DLL boundaries! You will need to call SetCurrentContext() + SetAllocatorFunctions()
// for each static/DLL boundary you are calling from. Read "Context and Memory Allocators" section of imgui.cpp for more details.
//#define Critisal_API __declspec( dllexport )
//#define Critisal_API __declspec( dllimport )

// default.chrome.Critisal_9328

#define Critisal_STB_SPRINTF_FILENAME    // "my_folder/stb_sprintf.h"    // only used if enabled
#define Critisal_DISABLE_STB_TRUETYPE_IMPLEMENTATION
#define Critisal_DISABLE_STB_RECT_PACK_IMPLEMENTATION

#define IM_VEC2_CLASS_EXTRA                                                     \
        constexpr ImVec2(const MyVec2& f) : x(f.x), y(f.y) {}                   \
        operator MyVec2() const { return MyVec2(x,y); }

#define IM_VEC4_CLASS_EXTRA                                                     \
        constexpr ImVec4(const MyVec4& f) : x(f.x), y(f.y), z(f.z), w(f.w) {}   \
        operator MyVec4() const { return MyVec4(x,y,z,w); }
*/

//---- Use 32-bit vertex indices (default is 16-bit) is one way to allow large meshes with more than 64K vertices.
// Your renderer backend will need to support it (most example renderer backends support both 16/32-bit indices).
// Another way to allow large meshes while keeping 16-bit indices is to handle ImDrawCmd::VtxOffset in your renderer.
// Read about ImGuiBackendFlags_RendererHasVtxOffset for details.
//#define ImDrawIdx unsigned int

//---- Override ImDrawCallback signature (will need to modify renderer backends accordingly)
//struct Critisal_ImDrawList;
//struct Critisal_ImDrawCmd;
//typedef void (*MyImDrawCallback)(const ImDrawList* draw_list, const ImDrawCmd* cmd, void* my_renderer_user_data);
//#define ImDrawCallback MyImDrawCallback

//---- Debug Tools: Macro to break in Debugger
// (use 'Metrics->Tools->Item Picker' to pick widgets with the mouse and break into them for easy debugging.)
//#define Critisal_IM_DEBUG_BREAK  IM_ASSERT(0)
//#define Critisal_IM_DEBUG_BREAK  __debugbreak()

//---- Debug Tools: Enable slower asserts
//#define Critisal_DEBUG_PARANOID

//---- Tip: You can add extra functions within the ImGui:: namespace, here or in your own headers files.

namespace ImGui
{
    void MyFunction(const char* name, const MyMatrix44& v);
}
