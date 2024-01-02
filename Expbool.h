#pragma once

// Converts an int to a bool, if the user specifies the "choice" param to 1 or greater, true is returned, if it is 0 or lower, false is returned. Why does Fusion's expression editor have no boolean parameter type?! Damn it!
#define TrueFalse(choice) (choice > 0) ? true : false