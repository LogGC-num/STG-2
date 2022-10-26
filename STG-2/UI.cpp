#include "UI.h"

extern int cWhite;

UI::UI() {

}



void UI::draw_UIbox() {
	DrawBox(UI_BOX_LEFT,UI_BOX_UPPER,UI_BOX_RIGHT,UI_BOX_DOWNNER,cWhite,FALSE);
}
