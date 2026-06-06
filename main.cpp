#include "imgui.h"

// Global variable to keep track of whether the menu is visible or hidden
bool g_ShowMenu = false;

// Variables to keep track of your feature toggles
static bool g_SuperSpeed = false;
static bool g_InfiniteAmmo = false;
static bool g_FlyMode = false;

extern "C" {
    // This function gets called by the game every single frame
    // 'button_state' will be 1 if the Y button is held down, and 0 if released
    void process_vr_input(int button_state) {
        
        // 1. Check if the controller button is being held down
        if (button_state == 1) {
            g_ShowMenu = true;
        } else {
            g_ShowMenu = false;
        }

        // 2. If it's held down, draw our ImGui layout on the screen
        if (g_ShowMenu) {
            // Begins a standard ImGui window panel
            ImGui::Begin("VR Mod Menu", &g_ShowMenu, ImGuiWindowFlags_AlwaysAutoResize);
            
            ImGui::Text("Hold Y to Keep Menu Open");
            ImGui::Separator();

            // Checkboxes: When clicked, they flip the true/false values automatically
            if (ImGui::Checkbox("Super Speed", &g_SuperSpeed)) {
                if (g_SuperSpeed) {
                    // Logic to increase player movement speed goes here
                }
            }

            if (ImGui::Checkbox("Infinite Ammo", &g_InfiniteAmmo)) {
                if (g_InfiniteAmmo) {
                    // Logic to lock ammo values goes here
                }
            }

            if (ImGui::Checkbox("Fly Mode", &g_FlyMode)) {
                if (g_FlyMode) {
                    // Logic to disable gravity goes here
                }
            }

            // Ends the ImGui window panel
            ImGui::End();
        }
    }
}
