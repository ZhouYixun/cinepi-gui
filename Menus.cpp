#include "Page.hpp"

#include <sstream>
#include <iomanip>
#include <string>

std::string floatToFormattedString(float value) {
    std::ostringstream oss;
    oss << std::setw(7) << std::setfill(' ') << std::fixed << std::setprecision(0) << value;
    return oss.str();
}

void Menus::show()
{
    menu_top();
    menu_bottom();
}

void Menus::menu_top()
{
    ImGuiIO &io = ImGui::GetIO(); (void)io;

    FrameBuffer fb = app.buffers.getBuffer();

    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,ImVec2(4.0f, 16.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing,ImVec2(16.0f, 4.0f));
    {   
        ImGui::SetNextWindowSize(io.DisplaySize);
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_MenuBar;
        window_flags |= ImGuiWindowFlags_NoDecoration;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoCollapse;
        window_flags |= ImGuiWindowFlags_NoNav;
        window_flags |= ImGuiWindowFlags_NoBackground;
        
        ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(0.0f, 0.0f, 0.0f, 0.5f)); 
        ImGui::Begin("Menus", NULL, window_flags);                         

        if (ImGui::BeginMenuBar())
        {
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 12);
            ImGui::Image((void*)(intptr_t)logo.texture, ImVec2(80, 80));
            ImGui::Separator();

            ImGui::PushFont(app.ui24);
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 16);
            ImGui::TextColored(ImVec4(0.39f, 0.39f, 0.39f, 1.00f), "FPS");
            ImGui::PopFont();

            if (ImGui::BeginMenu(floatToFormattedString(fb.framerate).c_str()))
            {
                
                ImGui::MenuItem("24");
                ImGui::MenuItem("30");
                ImGui::MenuItem("50");
                ImGui::EndMenu();
            }
            ImGui::Separator();

            ImGui::PushFont(app.ui24);
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 16);
            ImGui::TextColored(ImVec4(0.39f, 0.39f, 0.39f, 1.00f), "ISO");
            ImGui::PopFont();

            if (ImGui::BeginMenu("   100"))
            {
                ImGui::MenuItem("100");
                ImGui::MenuItem("200");
                ImGui::MenuItem("400");
                ImGui::MenuItem("800");
                ImGui::EndMenu();
            }
            ImGui::Separator();

            ImGui::PushFont(app.ui24);
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 16);
            ImGui::TextColored(ImVec4(0.39f, 0.39f, 0.39f, 1.00f), "SHT");
            ImGui::PopFont();

            if (ImGui::BeginMenu("   180°"))
            {
                if (ImGui::MenuItem("45°")) {  }
                if (ImGui::MenuItem("90°")) {  }
                if (ImGui::MenuItem("144°")) {  }
                if (ImGui::MenuItem("180°")) {  }
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::BeginMenu(ICON_FA_COG))
            {
                if (ImGui::MenuItem("ZEBRA")) {}
                if (ImGui::MenuItem("FOCUS")) {}
                if (ImGui::BeginMenu("HISTOGRAM"))
                { 
                    if (ImGui::MenuItem("ENABLE")) {}
                    if (ImGui::MenuItem("LUMA")) {}
                    ImGui::EndMenu();
                }
                
                if (ImGui::MenuItem("WAVE")) {}
                if (ImGui::MenuItem("FALSE")) {}
                if (ImGui::MenuItem("RGB")) {}

                if(1){
                    if (ImGui::BeginMenu("BAYER"))
                    { 
                        if (ImGui::MenuItem("SPLIT")) {}
                        ImGui::EndMenu();
                    }
                }

                if (ImGui::BeginMenu("OVERLAYS"))
                { 
                    if (ImGui::MenuItem("CROSS")) {}
                    if (ImGui::MenuItem("THIRDS")) {}
                    ImGui::EndMenu();
                }
                if (ImGui::MenuItem("DEMO")) { }
                if (ImGui::BeginMenu("ZOOM"))
                { 
                    if (ImGui::MenuItem("1x")) { }
                    if (ImGui::MenuItem("2x")) { }
                    if (ImGui::MenuItem("4x")) { }
                    if (ImGui::MenuItem("8x")) { }
                    if (ImGui::MenuItem("16x")) { }
                    ImGui::EndMenu();
                }
                ImGui::PushItemWidth(200);
                // maybe crash here
                // ImGui::SliderFloat("ZOOM", NULL, 0.0f, 16.0f);
                ImGui::EndMenu();
            }
            ImGui::Separator();

            ImGui::PushFont(app.ui24);
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 16);
            ImGui::TextColored(ImVec4(0.39f, 0.39f, 0.39f, 1.00f), "IRIS");
            ImGui::PopFont();

            if (ImGui::BeginMenu("     ---"))
            {
                ImGui::EndMenu();
            }
            ImGui::Separator();

            ImGui::PushFont(app.ui24);
            ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 16);
            ImGui::TextColored(ImVec4(0.39f, 0.39f, 0.39f, 1.00f), "WB");
            ImGui::PopFont();

            if (ImGui::BeginMenu("  5600k"))
            {

                ImGui::EndMenu();
            }
            ImGui::Separator();

            ImGui::EndMenuBar();   
        }
        ImGui::End();
        ImGui::PopStyleColor(1);
    }
    ImGui::PopStyleVar(2);
}

void Menus::menu_bottom()
{
    ImGuiIO &io = ImGui::GetIO(); (void)io;
    ImGui::PushStyleVar(ImGuiStyleVar_FramePadding,ImVec2(4.0f, 16.0f));
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing,ImVec2(32.0f, 4.0f));
    const ImGuiViewport *viewport = ImGui::GetMainViewport();

    // Set position to the bottom of the viewport
    ImGui::SetNextWindowPos(
        ImVec2(viewport->Pos.x,
                viewport->Pos.y + viewport->Size.y - ImGui::GetFrameHeight()));

    // Extend width to viewport width
    ImGui::SetNextWindowSize(ImVec2(viewport->Size.x, ImGui::GetFrameHeight()));

    // Add menu bar flag and disable everything else
    ImGuiWindowFlags flags =
        ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoInputs |
        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollWithMouse |
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoBackground |
        ImGuiWindowFlags_MenuBar;

    ImGui::PushStyleColor(ImGuiCol_MenuBarBg, ImVec4(0.0f, 0.0f, 0.0f, 0.5f)); 
    if (ImGui::Begin("StatusBar", nullptr, flags)) {

        if (ImGui::BeginMenuBar()) {

            // ImDrawList* draw_list = ImGui::GetWindowDrawList();
            // draw_list->AddCircleFilled(ImVec2(400, 1030), 17.0f, ImColor(1.0f, 0.0f, 0.0f), 20);
            // draw_list->AddText(ui48, ui48->FontSize, ImVec2(430, 1008), IM_COL32(255, 0, 0, 255), "REC");

            // ImGui::PushFont(ui36);
            // ImGui::PushFont(icons_font24);
            // ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            // ImGui::PopFont();
            // ImGui::PopFont();

            ImGui::Separator();
            ImGui::Text("FPS: %.1f FPS", io.Framerate);
            ImGui::Separator();
            ImGui::Text("GPU: %3.1f%%", app.stats.stat_gpu);
            ImGui::Separator();
            ImGui::Text("CPU: %3.1f%%", app.stats.stat_cpu);
            ImGui::Separator();

            ImGui::EndMenuBar();
        }
    ImGui::End();
    }
    ImGui::PopStyleColor(1);
    ImGui::PopStyleVar(2);
}

Page *make_menus_page(Application& app){
    return new Menus(app);
}
