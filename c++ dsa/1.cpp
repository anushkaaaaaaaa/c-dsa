// 3. Search for a number in an array
void array_search()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key;
    cout << "Enter key to search: ";
    cin >> key;
    int idx = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == key)
        {
            idx = i;
            break;
        }
    if (idx == -1)
        cout << "Not found\n";
    else
        cout << "Found at index " << idx << "\n";
}