touch -a ex03/bomb.txt | stat -s ex03/bomb.txt | cut -d ' ' -f9 | cut -d '=' -f2
