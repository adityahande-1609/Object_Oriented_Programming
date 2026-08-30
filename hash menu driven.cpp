#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cstdint>
using namespace std;
uint32_t rightRotate(uint32_t x, uint32_t n)
{
    return (x >> n) | (x << (32 - n));
}
const uint32_t K[64] =
{
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
    0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
    0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
    0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
    0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8fc, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
    0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
    0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
    0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
string sha256(const string& input)
{
    vector<uint8_t> data(input.begin(), input.end());
    uint64_t originalLength = data.size() * 8;
    data.push_back(0x80);

    while ((data.size() % 64) != 56)
    {
        data.push_back(0x00);
    }
    for (int i = 7; i >= 0; i--)
    {
        data.push_back(
            static_cast<uint8_t>(
                (originalLength >> (i * 8)) & 0xff
            )
        );
    }
    uint32_t H[8] =
    {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };
    for (size_t block = 0; block < data.size(); block += 64)
    {
        uint32_t W[64];
        for (int i = 0; i < 16; i++)
        {
            W[i] =
                (static_cast<uint32_t>(data[block + i * 4]) << 24) |
                (static_cast<uint32_t>(data[block + i * 4 + 1]) << 16) |
                (static_cast<uint32_t>(data[block + i * 4 + 2]) << 8) |
                (static_cast<uint32_t>(data[block + i * 4 + 3]));
        }
        for (int i = 16; i < 64; i++)
        {
            uint32_t s0 =
                rightRotate(W[i - 15], 7) ^
                rightRotate(W[i - 15], 18) ^
                (W[i - 15] >> 3);
            uint32_t s1 =
                rightRotate(W[i - 2], 17) ^
                rightRotate(W[i - 2], 19) ^
                (W[i - 2] >> 10);
            W[i] = W[i - 16] + s0 + W[i - 7] + s1;
        }
        uint32_t a = H[0];
        uint32_t b = H[1];
        uint32_t c = H[2];
        uint32_t d = H[3];
        uint32_t e = H[4];
        uint32_t f = H[5];
        uint32_t g = H[6];
        uint32_t h = H[7];
        for (int i = 0; i < 64; i++)
        {
            uint32_t S1 =
                rightRotate(e, 6) ^
                rightRotate(e, 11) ^
                rightRotate(e, 25);
            uint32_t ch =
                (e & f) ^ ((~e) & g);
            uint32_t temp1 =
                h + S1 + ch + K[i] + W[i];
            uint32_t S0 =
                rightRotate(a, 2) ^
                rightRotate(a, 13) ^
                rightRotate(a, 22);
            uint32_t maj =
                (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }
        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }
    stringstream result;
    for (int i = 0; i < 8; i++)
    {
        result << hex
               << setw(8)
               << setfill('0')
               << H[i];
    }
    return result.str();
}
class Evidence
{
public:
    string userName;
    string fileName;
    string fileData;
    string hash;
    Evidence(string user, string file, string data)
    {
        userName = user;
        fileName = file;
        fileData = data;
        string dataToHash =
            "USER:" + userName +
            "|FILE:" + fileName +
            "|DATA:" + fileData;
        hash = sha256(dataToHash);
    }
};
bool hashAlreadyExists(
    const vector<Evidence>& evidenceList,
    string newHash
)
{
    for (int i = 0; i < evidenceList.size(); i++)
    {
        if (evidenceList[i].hash == newHash)
        {
            return true;
        }
    }
    return false;
}
void registerEvidence(vector<Evidence>& evidenceList)
{
    string userName;
    string fileName;
    string fileData;
    cin.ignore();
    cout << "\n========== REGISTER EVIDENCE ==========\n";
    cout << "Enter user name: ";
    getline(cin, userName);
    cout << "Enter evidence file name: ";
    getline(cin, fileName);
    cout << "Enter evidence data: ";
    getline(cin, fileData);
    Evidence newEvidence(
        userName,
        fileName,
        fileData
    );
    if (hashAlreadyExists(
            evidenceList,
            newEvidence.hash))
    {
        cout << "\n=====================================\n";
        cout << "      FILE ALREADY REGISTERED\n";
        cout << "=====================================\n";

        cout << "\nHash:\n";
        cout << newEvidence.hash << endl;

        return;
    }
    evidenceList.push_back(newEvidence);
    cout << "\n=====================================\n";
    cout << "       EVIDENCE REGISTERED\n";
    cout << "=====================================\n";
    cout << "\nUser Name : "
         << newEvidence.userName << endl;
    cout << "File Name : "
         << newEvidence.fileName << endl;
    cout << "\nSHA-256 Hash:\n"
         << newEvidence.hash << endl;
}
void retrieveEvidence(
    const vector<Evidence>& evidenceList
)
{
    if (evidenceList.empty())
    {
        cout << "\nNo evidence has been registered yet.\n";
        return;
    }
    string searchHash;
    cin.ignore();
    cout << "\n========== RETRIEVE EVIDENCE ==========\n";
    cout << "Enter SHA-256 hash: ";
    getline(cin, searchHash);
    bool found = false;
    for (int i = 0; i < evidenceList.size(); i++)
    {
        if (evidenceList[i].hash == searchHash)
        {
            cout << "\n=====================================\n";
            cout << "        EVIDENCE FOUND\n";
            cout << "=====================================\n";
            cout << "\nUser Name : "
                 << evidenceList[i].userName << endl;
            cout << "File Name : "
                 << evidenceList[i].fileName << endl;
            cout << "File Data : "
                 << evidenceList[i].fileData << endl;
            cout << "\nSHA-256 Hash:\n"
                 << evidenceList[i].hash << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "\n❌ No evidence found with this hash.\n";
    }
}
void displayAllEvidence(
    const vector<Evidence>& evidenceList
)
{
    if (evidenceList.empty())
    {
        cout << "\nNo evidence registered.\n";
        return;
    }
    cout << "\n========== ALL REGISTERED EVIDENCE ==========\n";
    for (int i = 0; i < evidenceList.size(); i++)
    {
        cout << "\nEvidence #" << i + 1 << endl;
        cout << "User       : "
             << evidenceList[i].userName << endl;
        cout << "File       : "
             << evidenceList[i].fileName << endl;
        cout << "Data       : "
             << evidenceList[i].fileData << endl;
        cout << "SHA-256    : "
             << evidenceList[i].hash << endl;
        cout << "---------------------------------------------\n";
    }
}
int main()
{
    vector<Evidence> evidenceList;
    int choice;
    do
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "       SECURE DIGITAL EVIDENCE SYSTEM\n";
        cout << "============================================\n";
        cout << "\n1. Register Evidence";
        cout << "\n2. Retrieve Evidence";
        cout << "\n3. View All Evidence";
        cout << "\n4. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                registerEvidence(evidenceList);
                break;
            case 2:
                retrieveEvidence(evidenceList);
                break;
            case 3:
                displayAllEvidence(evidenceList);
                break;
            case 4:
                cout << "\nExiting system...\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    }
    while (choice != 4);
    return 0;
}
