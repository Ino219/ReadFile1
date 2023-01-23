#include "MyForm.h"

using namespace ReadFile1;

[STAThreadAttribute]

int main() {
	System::Windows::Forms::Application::Run(gcnew MyForm());
	return 0;
}