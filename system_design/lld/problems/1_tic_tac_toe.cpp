#include <bits/stdc++.h>

using namespace std;

enum MarkerType
{
    X,
    O
};

class Marker
{
private:
    MarkerType type;

public:
    Marker(MarkerType type)
    {
        this->type = type;
    }

    MarkerType getType()
    {
        return type;
    }
};

class MarkerX : public Marker
{
public:
    MarkerX() : Marker(X) {}
};

class MarkerO : public Marker
{
public:
    MarkerO() : Marker(O) {}
};

class Player
{
private:
    int id;
    Marker *marker;

public:
    Player(int id, Marker *marker)
    {
        this->id = id;
        this->marker = marker;
    }

    int getId()
    {
        return id;
    }

    Marker *getMarker()
    {
        return marker;
    }

    MarkerType getMarkerType()
    {
        return marker->getType();
    }
};

class Board
{
private:
    vector<vector<Marker *>> board;
    int freeCellsCount = 0;

public:
    Board(int n)
    {
        board = vector<vector<Marker *>>(n, vector<Marker *>(n, nullptr));
        freeCellsCount = n * n;
    }

    int getSize()
    {
        return board.size();
    }

    bool mark(Marker *marker, int x, int y)
    {
        if (board[x][y] == nullptr)
        {
            board[x][y] = marker;
            freeCellsCount--;
            return true;
        }

        return false;
    }

    int getFreeCellsCount()
    {
        return freeCellsCount;
    }

    bool checkWinner(Marker *marker, int x, int y)
    {
        int n = getSize();

        bool rowMatch = true;
        bool colMatch = true;
        bool diagMatch = true;
        bool antiDiagMatch = true;

        for (int i = 0; i < n; i++)
        {
            if (board[x][i] == nullptr || board[x][i]->getType() != marker->getType())
            {
                rowMatch = false;
                break;
            }
        }
        if (rowMatch)
        {
            return true;
        }

        for (int i = 0; i < n; i++)
        {
            if (board[i][y] == nullptr || board[i][y]->getType() != marker->getType())
            {
                colMatch = false;
                break;
            }
        }
        if (colMatch)
        {
            return true;
        }

        if (x == y)
        {
            for (int i = 0, j = 0; i < n; i++, j++)
            {
                if (board[i][j] == nullptr || board[i][j]->getType() != marker->getType())
                {
                    diagMatch = false;
                    break;
                }
            }
        }
        else
        {
            diagMatch = false;
        }
        if (diagMatch)
        {
            return true;
        }

        if (x + y == n - 1)
        {
            for (int i = 0; i < n; i++)
            {
                int j = n - i - 1;
                if (board[i][j] == nullptr || board[i][j]->getType() != marker->getType())
                {
                    antiDiagMatch = false;
                    break;
                }
            }
        }
        else
        {
            antiDiagMatch = false;
        }

        return antiDiagMatch;
    }

    void print()
    {
        int n = getSize();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Marker *m = board[i][j];
                if (m == nullptr)
                {
                    cout << "_ ";
                }
                else
                {
                    cout << m->getType() << " ";
                }
            }
            cout << endl;
        }
    }
};

class Game
{
private:
    Board *board;
    deque<Player *> players;

public:
    Game(int size)
    {
        board = new Board(size);

        Marker *m1 = new MarkerX();
        Player *p1 = new Player(0, m1);
        players.push_back(p1);

        Marker *m2 = new MarkerO();
        Player *p2 = new Player(1, m2);
        players.push_back(p2);
    }

    int start()
    {
        bool winnerFound = false;

        board->print();

        while (!winnerFound)
        {
            if (board->getFreeCellsCount() == 0)
            {
                return -1;
            }

            Player *p = players.front();
            players.pop_front();
            players.push_back(p);

            int x, y;

            while (true)
            {
                cout << "Enter position for player " << p->getId() << ": ";
                cin >> x >> y;
                cout << x << " " << y << endl;

                if (board->mark(p->getMarker(), x, y))
                {
                    break;
                }
                cout << "Position already marked, enter different position." << endl;
            }

            board->print();

            winnerFound = board->checkWinner(p->getMarker(), x, y);
            if (winnerFound)
            {
                return p->getId();
            }
        }

        return -1;
    }
};

int main()
{
    Game *game = new Game(3);
    int winner = game->start();
    if (winner == -1)
    {
        cout << "Tie" << endl;
    }
    else
    {
        cout << "Winner is player " << winner << endl;
    }
}

/*

Entities:
- MarkerType
- Marker
- Player
- Board
- Game

Inheritance:
- MarkerX is Marker
- MarkerO is Marker

Relations
- Marker has MarkerType
- Player has Marker
- Board has Marker
- Game has board and players

*/
