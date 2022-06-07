# Qt-D-Bus-Sleep-Inhibit-Linux
Lock screen off for linux. Use methodology qdbus. 
Use 2 methods: 
- void preventDisplay(const QString &reason); (BAN SLEEP/ reason - a description of what the lock is for)
- void allowDisplay();
