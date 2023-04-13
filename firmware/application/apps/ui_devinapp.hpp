
#ifndef __UI_DEVINAPP_H__
#define __UI_DEVINAPP_H__

#include "ui.hpp"
#include "ui_widget.hpp"
#include "ui_navigation.hpp"
#include "string_format.hpp"

namespace ui
{
    class DevinAppView : public View                                // App class declaration
    {
    public:
        // Public declarations
    	void focus() override;                              // ui::View function override

        DevinAppView(NavigationView &nav);                        // App class init function declaration
        std::string title() const override { return "Devin's App"; }; // App title

    private:
        // Variables
        int kProgressMax = 100;
        uint32_t progress = 0; 

        Button my_button{
            {70, 128, 120, 24}, // Coordinates are: int:x (px), int:y (px), int:width (px), int:height (px)
            "my_button_text"
        };

        LiveDateTime my_liveDateTime {
            {6*8, 22*8, 19*8, 20 },       // Coordinates are: int:x (px), int:y (px), int:width (px), int:height (px)
        };

        Labels label_progress {
            {{8*8, 33*8},                  // Coordinates are: int:x(px), int:y(px)
            "Progress:     %",             // Title
            Color::light_grey()}           // Title color
        };

        NumberField numberField_progress {
            {18*8, 33*8},                  // Coordinates
            3,                             // Length of number
            {0,kProgressMax},              // Range
            1,                             // Step
            '0',                           // Fill Char
            false                          // Loop?
        };
        
        ProgressBar progressBar_progress {
            {2*8, 35*8, 208, 16 },         // Coordinates and Dimensions
        };
    };
} 

#endif