
#include <iostream>

using namespace std;

bool A;   //A will represent 'has a rocket'
bool B;   //B will represent 'is an astronaut'
bool C;   //C will represent 'is highly trained'
bool D;   //D will represent 'is educated'
bool funImp(bool, bool);

int main()
{
    cout << "The following propositional logic will be tested for validity:\n" << endl;
    cout << "Statement A: If someone has a rocket, that implies they're an astronaut." << endl;
    cout << "Statement B: If someone is an astronaut, that implies they're highly trained." << endl;
    cout << "Statement C: If someone is highly trained, that implies they're educated." << endl;
    cout << "\nConclusion: A person is educated, that implies they have a rocket.\n" << endl;
    cout << "The following input combinations invalidate the propositional logic." << endl;
    cout << "       (if no combinations are displayed, the logic is VALID)\n" << endl;
    cout << " Rocket  Astronaut  Trained  Educated" << endl;

    int i, j, k, l;
    for (i = 0; i < 2; ++i) {          //A will be evaluated at 0 then 1 (false then true)
        A = i;
        for (j = 0; j < 2; ++j) {
            B = j;                     //B will be evaluated at 0 then 1 (false then true)
            for (k = 0; k < 2; ++k) {
                C = k;                 //C will be evaluated at 0 then 1 (false then true)
                for (l = 0; l < 2; ++l) {
                    D = l;

                    bool cond1 = funImp(A, B);
                    bool cond2 = funImp(B, C);
                    bool cond3 = funImp(C, D);
                    bool cond4 = funImp(D, A);

                    bool inv = (cond1 && cond2 && cond3 && !cond4);

                    if (inv) {
                        cout << "    " << A << "        " << B << "         ";
                        cout << C << "        " << D << endl;
                    }
                }
            }
        }
    }
}

bool funImp(bool A, bool B) {
    if (!(A && !B)) {
        return true;
    }
    else {
        return false;
    }
}
