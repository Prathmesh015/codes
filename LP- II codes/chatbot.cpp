#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string toLowerCase(string text) {
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

int main() {
    string userInput;
    cout << "   Welcome to Customer Support Chatbot   \n";
    cout << "Hello! I am your customer support assistant.\n";
    cout << "You can ask me about:\n";
    cout << "- product\n";
    cout << "- price\n";
    cout << "- order status\n";
    cout << "- return policy\n";
    cout << "- contact\n";
    cout << "Type 'exit' to end the chat.\n\n";

    while (true) {
        cout << "You: ";
        getline(cin, userInput);

        userInput = toLowerCase(userInput);

        if (userInput == "exit") {
            cout << "Bot: Thank you for chatting with us. Have a great day!\n";
            break;
        }
        else if (userInput.find("hello") != string::npos || userInput.find("hi") != string::npos) {
            cout << "Bot: Hello! How can I help you today?\n";
        }
        else if (userInput.find("product") != string::npos) {
            cout << "Bot: We offer laptops, smartphones, headphones, and smartwatches.\n";
        }
        else if (userInput.find("price") != string::npos) {
            cout << "Bot: Prices vary by product. Please mention the product name for exact pricing.\n";
        }
        else if (userInput.find("order status") != string::npos || userInput.find("track order") != string::npos) {
            cout << "Bot: Please enter your order ID on our website to track your order.\n";
        }
        else if (userInput.find("return") != string::npos) {
            cout << "Bot: Our return policy allows returns within 7 days of delivery.\n";
        }
        else if (userInput.find("contact") != string::npos) {
            cout << "Bot: You can contact us at support@shop.com or call 1800-123-456.\n";
        }
        else if (userInput.find("thank") != string::npos) {
            cout << "Bot: You're welcome! Happy to help.\n";
        }
        else {
            cout << "Bot: Sorry, I didn't understand that. Please ask about product, price, order status, return policy, or contact.\n";
        }
    }

    return 0;
}