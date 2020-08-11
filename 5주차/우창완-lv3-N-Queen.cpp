void makeWall(int cnt)

{
    if (cnt == 3)  //벽을 세개 만들었으므로

    {
        BFS();

        return;
    }

    for (int i = 0; i < N; i++)

        for (int j = 0; j < M; j++)

            if (temp[i][j] == 0)

            {
                temp[i][j] = 1;  //마찬가지로 해당칸에 새우고

                makeWall(cnt + 1);

                temp[i][j] = 0;  //다시 허문다
            }
}

int main(void)

{
    cin >> N >> M;

    for (int i = 0; i < N; i++)

        for (int j = 0; j < M; j++)

            cin >> lab[i][j];

    for (int i = 0; i < N; i++)

        for (int j = 0; j < M; j++)

            if (lab[i][j] == 0)  //빈칸 발견 시

            {
                //연구실 상태를 복사한다

                for (int k = 0; k < N; k++)

                    for (int l = 0; l < M; l++)

                        temp[k][l] = lab[k][l];

                temp[i][j] = 1;  //해당 칸에 벽을 세운다

                makeWall(1);  //벽을 세운 상태이므로 cnt = 1

                temp[i][j] = 0;  //다시 허문다
            }

    cout << result << endl;

    return 0;
}