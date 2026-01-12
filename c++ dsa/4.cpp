// 6. Store marks of 10 students in 5 courses (2D array)
void store_marks_2d()
{
    const int students = 10, courses = 5;
    vector<vector<int>> marks(students, vector<int>(courses));
    cout << "Enter marks for 10 students (5 courses each):\n";
    for (int i = 0; i < students; i++)
    {
        cout << "Student " << i << ": ";
        for (int j = 0; j < courses; j++)
            cin >> marks[i][j];
    }
    cout << "Displaying marks table:\n";
    for (int i = 0; i < students; i++)
    {
        for (int j = 0; j < courses; j++)
            cout << marks[i][j] << " ";
        cout << "\n";
    }
}