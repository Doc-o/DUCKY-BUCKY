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

## 🧠 How It Works

1. Launches hidden PowerShell via `Win+R`.
2. Executes a Base64-encoded PowerShell payload (reverse shell).
3. Adds a new administrator user.
4. Disables Windows Defender real-time protection.
5. Creates persistence by writing encoded command to startup registry.

## 🧪 Usage

1. Plug in the Digispark to a Windows machine.
2. The payload triggers and performs actions automatically.
3. Use a netcat listener to catch the reverse shell.

```bash
nc -lvnp 4444


