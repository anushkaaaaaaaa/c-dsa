// 4. Sort an array
void array_sorting()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    cout << "Sorted: ";
    for (int v : a)
        cout << v << " ";
    cout << "\n";
}
