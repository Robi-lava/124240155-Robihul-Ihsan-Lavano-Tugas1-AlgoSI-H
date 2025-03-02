#include <iostream>
using namespace std;

string tipePasukan[3] = {"infantry", "archer", "kavaleri"};
bool nemu = false;

struct batalyon
{
    int id;
    int jumlah;
    string namaGeneral;
    string tipe;
};
batalyon pasukan[100];
int jmlh_index = 0;

bool nama_ada(batalyon pasukan[], string nama)
{
    for (int i = 0; i < jmlh_index; i++)
    {
        if (pasukan[i].namaGeneral == nama)
        {
            return true;
        }
    }
    return false;
}
void tambah_batalyon(batalyon pasukan[])
{
    string *type = tipePasukan;
    cin.ignore();
    string nama;
    bool found = false;
    do
    {
        cout << "Input General Name : ";
        getline(cin, nama);

        if (nama_ada(pasukan, nama))
        {
            cout << "Error 303: Nama" << " - " << nama << " - " << "telah ada dalam list Silakan masukkan nama lain.\n ";
            system("pause");
        }
    } while (nama_ada(pasukan, nama)); // Ulangi jika nama sudah ada
    pasukan[jmlh_index].namaGeneral = nama;  // NAMA
    pasukan[jmlh_index].id = jmlh_index + 1; // ID
    while (!found)                           // sequential search
    {
        cout << "Input Soldier Type (Infantry, Kavaleri, Archer): ";
        cin >> pasukan[jmlh_index].tipe;
        for (int i = 0; i < 3; i++)
        {
            if (pasukan[jmlh_index].tipe == *(type + i))
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Tipe pasukan tidak valid! Silakan masukkan lagi.\n";
        }
    }
    cout << "Input Soldier Quantity: ";
    while (!(cin >> pasukan[jmlh_index].jumlah) || pasukan[jmlh_index].jumlah <= 1)
    {
        cout << "Error: Jumlah harus > 0, silakan coba lagi: ";
    }
    jmlh_index++;
}
void cari_batalyon(batalyon pasukan[])
// binary search
{
    cin.ignore();
    int awal = 0, akhir = jmlh_index - 1, tengah;
    bool found = false;
    string cari;
    cout << "Nama General yang ingin anda cari : " << '\n';
    getline(cin, cari);
    while (!found && (awal <= akhir))
    {
        tengah = (awal + akhir) / 2;
        if (pasukan[tengah].namaGeneral == cari)
        {
            found = true;
        }
        else if (pasukan[tengah].namaGeneral > cari)
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }
    if (found)
    {
        cout << "General ditemukan!" << '\n';
        cout << "ID : " << tengah + 1 << endl;
        cout << "Nama : " << pasukan[tengah].namaGeneral << '\n';
        cout << "Tipe Pasukan : " << pasukan[tengah].tipe << endl;
        cout << "Jumlah Pasukan : " << pasukan[tengah].jumlah << '\n';
        system("pause");
    }
    else
    {
        cout << "Tidak ada general bernama " << cari << " dalam Array." << endl;
    }
}
main()
{
    int menu;
    char kembali;
    string keluar;

    do
    {

        cout << "Daftar Menu\n";
        cout << "1. Tambah Batalyon\n";
        cout << "2. Cari Batalyon\n";
        cout << "Pilih Menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambah_batalyon(pasukan);
            cout << "\nApakah anda ingin melanjutkan? (ya/tidak) = ";
            cin >> keluar;
            break;
        case 2:
            cari_batalyon(pasukan);
            cout << "\nApakah anda ingin melanjutkan? (ya/tidak) = ";
            cin >> keluar;
            break;
        default:
            cout << "Menu tidak tersedia.\n";
            break;
        }

    } while (keluar == "ya");
}