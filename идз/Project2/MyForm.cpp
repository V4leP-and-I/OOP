#include "MyForm.h"
#include <windows.h>
#include <stdio.h>
using namespace std;

using namespace System;
using namespace System::Windows::Forms;
using namespace Redact;

[STAThread]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Redact::Redactor form;
    Application::Run(% form);
}

