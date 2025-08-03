# Digispark Rubber Ducky – Advanced Persistence and Reverse Shell Payload

This project demonstrates an advanced Rubber Ducky-style penetration test using a Digispark USB (ATTiny85). The device acts as a keystroke injector to automate execution of PowerShell commands for:

- Reverse shell access
- Antivirus disablement
- Persistence via registry
- User creation

## 🔧 Features

- Hidden PowerShell execution
- Base64-encoded reverse shell
- Adds a privileged user account
- Disables Microsoft Defender
- Creates persistence via registry

## 💻 Requirements

- Digispark USB Board (ATTiny85)
- Arduino IDE with Digispark drivers
- Hosted listener (`nc` or Metasploit)
- Windows target machine with USB support and internet access

## 🗂 Project Structure

