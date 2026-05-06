#include <iostream>
using namespace std;

int main() {
    int systolic, diastolic;
    float sugar;

    cout << "===== HEALTH EXPERT SYSTEM (BP & SUGAR) =====\n";

    // Input BP
    cout << "\nEnter Systolic BP: ";
    cin >> systolic;

    cout << "Enter Diastolic BP: ";
    cin >> diastolic;

    // Input Sugar
    cout << "Enter Fasting Blood Sugar level: ";
    cin >> sugar;

    string bpStatus, sugarStatus;

    // BP Analysis
    if (systolic < 120 && diastolic < 80) {
        bpStatus = "Normal";
    }
    else if (systolic <= 139 || diastolic <= 89) {
        bpStatus = "Pre-Hypertension";
    }
    else {
        bpStatus = "Hypertension (High BP)";
    }

    // Sugar Analysis
    if (sugar < 100) {
        sugarStatus = "Normal";
    }
    else if (sugar <= 125) {
        sugarStatus = "Pre-Diabetes";
    }
    else {
        sugarStatus = "Diabetes";
    }

    // Output Results
    cout << "\n--- RESULT ---\n";
    cout << "BP Status: " << bpStatus << endl;
    cout << "Sugar Status: " << sugarStatus << endl;

    // Advice Section
    cout << "\n--- EXPERT ADVICE ---\n";

    if (bpStatus == "Hypertension (High BP)" || sugarStatus == "Diabetes") {
        cout << "⚠️ Serious Condition: Consult doctor immediately.\n";

        cout << "\nRecommended Diet:\n";
        cout << "- Low salt food\n";
        cout << "- Avoid sugar & junk food\n";
        cout << "- Eat fruits, vegetables, whole grains\n";

        cout << "\nWhat to Do:\n";
        cout << "- Daily exercise (30 minutes)\n";
        cout << "- Monitor BP and sugar regularly\n";
        cout << "- Take medicines as prescribed\n";
    }
    else if (bpStatus == "Pre-Hypertension" || sugarStatus == "Pre-Diabetes") {
        cout << "⚠️ Warning Stage: Take care of your health.\n";

        cout << "\nRecommended Diet:\n";
        cout << "- Reduce sugar and salt intake\n";
        cout << "- Avoid oily and fried food\n";
        cout << "- Drink plenty of water\n";

        cout << "\nWhat to Do:\n";
        cout << "- Start regular exercise\n";
        cout << "- Maintain healthy weight\n";
        cout << "- Check health monthly\n";
    }
    else {
        cout << "✅ You are healthy.\n";

        cout << "\nRecommended Diet:\n";
        cout << "- Balanced diet (fruits, vegetables, proteins)\n";

        cout << "\nWhat to Do:\n";
        cout << "- Continue exercise\n";
        cout << "- Maintain healthy lifestyle\n";
    }

    return 0;
}