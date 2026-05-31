#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;






class UrlShortener
{
private:
    unordered_map<string, string> links;

public:
    void addLink(const string& shortCode, const string& longUrl)
    {
        links[shortCode] = longUrl;
        cout << "Link added successfully.\n";
    }

    void getLink(const string& shortCode)
    {
        if (links.find(shortCode) != links.end())
        {
            cout << "Long URL: " << links[shortCode] << endl;
        }
        else
        {
            cout << "Short code not found.\n";
        }
    }

    void checkCode(const string& shortCode)
    {
        if (links.find(shortCode) != links.end())
        {
            cout << "Short code exists.\n";
        }
        else
        {
            cout << "Short code does not exist.\n";
        }
    }

    void showAllLinks()
    {
        if (links.empty())
        {
            cout << "No links found.\n";
            return;
        }

        cout << "\nAll shortened links:\n";

        for (const auto& pair : links)
        {
            cout << pair.first << " -> " << pair.second << endl;
        }
    }

    void updateLink(const string& shortCode, const string& newUrl)
    {
        if (links.find(shortCode) != links.end())
        {
            links[shortCode] = newUrl;
            cout << "Link updated successfully.\n";
        }
        else
        {
            cout << "Short code not found.\n";
        }
    }
};









int main()
{
    UrlShortener service;

    int choice;

    do
    {
        cout << "\n      MENU      \n";
        cout << "1. Add link\n";
        cout << "2. Get long URL\n";
        cout << "3. Check short code\n";
        cout << "4. Show all links\n";
        cout << "5. Update long URL\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        string shortCode;
        string longUrl;

        switch (choice)
        {
        case 1:
            cout << "Enter short code: ";
            cin >> shortCode;

            cout << "Enter long URL: ";
            cin >> longUrl;

            service.addLink(shortCode, longUrl);
            break;

        case 2:
            cout << "Enter short code: ";
            cin >> shortCode;

            service.getLink(shortCode);
            break;

        case 3:
            cout << "Enter short code: ";
            cin >> shortCode;

            service.checkCode(shortCode);
            break;

        case 4:
            service.showAllLinks();
            break;

        case 5:
            cout << "Enter short code: ";
            cin >> shortCode;

            cout << "Enter new long URL: ";
            cin >> longUrl;

            service.updateLink(shortCode, longUrl);
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}