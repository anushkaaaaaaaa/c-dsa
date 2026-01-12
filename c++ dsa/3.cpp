// 5. Merge two sorted arrays
void merge_two_sorted()
{
    int n, m;
    cout << "Enter sizes n m: ";
    cin >> n >> m;
    vector<int> A(n), B(m);
    cout << "Enter sorted A:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter sorted B:\n";
    for (int i = 0; i < m; i++)
        cin >> B[i];
    vector<int> C;
    C.reserve(n + m);
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
            C.push_back(A[i++]);
        else
            C.push_back(B[j++]);
    }
    while (i < n)
        C.push_back(A[i++]);
    while (j < m)
        C.push_back(B[j++]);
    cout << "Merged: ";
    for (int v : C)
        cout << v << " ";
    cout << "\n";
}