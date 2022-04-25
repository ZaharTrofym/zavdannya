#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class PasswordGenerator {
    private:
        string latters = "abcdefgABCDEFG";
        string numbers = "1234567890";
        string spec = "!@#$%^&*";
        bool specTF = false;
    public:
        string generatePass(string password) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    password += latters[rand() % latters.length()];
                }
                if (specTF == false && rand() % 2 == 1) {
                    password += spec[rand() % spec.length()];
                    specTF = true;
                }
                else if (i == 3 && specTF == false) {
                    password += spec[rand() % spec.length()];
                    specTF = true;
                }
                else {
                    password += numbers[rand() % numbers.length()];
                }
            }
            return password;
        }
};

int main() {
    srand(time(NULL));
    PasswordGenerator Password;
    string password;
    
    password = Password.generatePass(password);

    cout << password;
}