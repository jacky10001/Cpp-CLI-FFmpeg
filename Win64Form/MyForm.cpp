#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Win32Form::MyForm form;  // MyProject �ݮھڱM�צW�ٶi�����
    Application::Run(% form);
}