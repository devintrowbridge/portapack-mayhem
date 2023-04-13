#include "ui_devinapp.hpp"
#include "portapack.hpp"
#include "ui_widget.hpp"
#include <cstring>

using namespace portapack;

namespace ui
{
    void DevinAppView::focus() {                               // Default selection to button_helloWorld when app starts
	    my_button.focus();
    }

    DevinAppView::DevinAppView(NavigationView &nav) // Application Main
    {
        add_children({                                       // Add pointers for widgets
            &my_button,
            &label_progress,
            &numberField_progress,
            &progressBar_progress,
            &my_liveDateTime,
        });

        progressBar_progress.set_max(kProgressMax);          // Set max for progress bar

        my_button.on_select = [this](Button &){      // Button logic
            if(progress < 100) { 
                numberField_progress.set_value(100);         // Because numberField_progress has an on_change function,
            } else {                                         // progressBar_progress will update automatically.
                numberField_progress.set_value(0);
            }
        };   

        numberField_progress.on_change = [this](int32_t v) { // When NumberField is changed
            progress = v;
            progressBar_progress.set_value(progress);
        };

        my_liveDateTime.set_seconds_enabled(true);
    }
}