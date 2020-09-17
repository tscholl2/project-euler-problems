/*
In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand	 	Player 1	 	Player 2	 	Winner
1	 	5H 5C 6S 7S KD
Pair of Fives
 	2C 3S 8S 8D TD
Pair of Eights
 	Player 2
2	 	5D 8C 9S JS AC
Highest card Ace
 	2C 5C 7D 8S QH
Highest card Queen
 	Player 1
3	 	2D 9C AS AH AC
Three Aces
 	3D 6D 7D TD QD
Flush with Diamonds
 	Player 2
4	 	4D 6S 9H QH QC
Pair of Queens
Highest card Nine
 	3D 6D 7H QD QS
Pair of Queens
Highest card Seven
 	Player 1
5	 	2H 2D 4C 4D 4S
Full House
With Three Fours
 	3C 3D 3S 9S 9D
Full House
with Three Threes
 	Player 1
The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards. You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?
*/
#include <iostream>
#include <array>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using byte_t = unsigned char;
using card_t = std::array<byte_t, 2>;
using hand_t = std::array<card_t, 5>;

const std::map<byte_t, byte_t> values{{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};
const std::map<byte_t, byte_t> suits{{'H', 1}, {'C', 2}, {'D', 3}, {'S', 4}};

#define VALU(c) values.at(c[0])
#define SUIT(c) suits.at(c[1])

//One Pair: Two cards of the same value.
byte_t one_pair(const hand_t &h)
{
    std::array<int, 32> arr{};
    for (const auto &c : h)
        arr[VALU(c)]++;
    auto i = std::find(arr.begin(), arr.end(), 2);
    return i == arr.end() ? 0 : std::distance(arr.begin(), i);
}

//Two Pairs: Two different pairs.
byte_t two_pair(const hand_t &h)
{
    std::array<int, 32> arr{};
    for (const auto &c : h)
        arr[VALU(c)]++;
    auto i = std::find(arr.rbegin(), arr.rend(), 2);
    if (i == arr.rend())
        return 0;
    auto v1 = 31 - std::distance(arr.rbegin(), i);
    auto j = std::find(arr.begin(), arr.end(), 2);
    auto v2 = std::distance(arr.begin(), j);
    return v1 == v2 ? 0 : (v1 << 4) | v2;
}

//Three of a Kind: Three cards of the same value.
byte_t three_of_a_kind(const hand_t &h)
{
    std::array<int, 32> arr{};
    for (const auto &c : h)
        arr[VALU(c)]++;
    auto i = std::find(arr.begin(), arr.end(), 3);
    return i == arr.end() ? 0 : std::distance(arr.begin(), i);
}

//Straight: All cards are consecutive values.
byte_t straight(const hand_t &h)
{
    std::array<byte_t, 5> arr{VALU(h[0]), VALU(h[1]), VALU(h[2]), VALU(h[3]), VALU(h[4])};
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < 4; ++i)
        if (arr[i] + 1 != arr[i + 1])
            return 0;
    return arr[4];
}

//Flush: All cards of the same suit.
byte_t flush(const hand_t &h)
{
    std::array<int, 32> arr{};
    for (const auto &c : h)
        arr[SUIT(c)]++;
    auto i = std::find(arr.begin(), arr.end(), 5);
    return i == arr.end() ? 0 : std::distance(arr.begin(), i);
}

//Full House: Three of a kind and a pair.
byte_t full_house(const hand_t &h)
{
    auto v3 = three_of_a_kind(h);
    auto v2 = one_pair(h);
    if (!v3 || !v2)
        return 0;
    return (v3 << 4) | v2;
}

//Four of a Kind: Four cards of the same value.
byte_t four_of_a_kind(const hand_t &h)
{
    std::array<int, 32> arr{};
    for (const auto &c : h)
        arr[VALU(c)]++;
    auto i = std::find(arr.begin(), arr.end(), 4);
    return i == arr.end() ? 0 : std::distance(arr.begin(), i);
}

//Straight Flush: All cards are consecutive values of same suit.
byte_t straight_flush(const hand_t &h)
{
    auto s = straight(h);
    auto f = flush(h);
    if (!s || !f)
        return 0;
    return (s << 4) | f;
}

//Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
byte_t royal_flush(const hand_t &h)
{
    auto s = straight_flush(h);
    if (!s || s < 13)
        return 0;
    return (s << 4) | SUIT(h[0]);
}

std::vector<hand_t> parse(const std::string &s)
{
    // s = "8C TS KC 9H 4S"
    std::vector<hand_t> hands;
    int i = 0;
    hand_t h;
    for (auto c : s)
    {
        if (!std::isspace(c) && i < 10)
            h[i / 2][i % 2] = c, ++i;
        if (i == 10)
        {
            hands.push_back(h);
            i = 0;
            h = hand_t{};
        }
    }
    return hands;
}

int cmp(hand_t h1, hand_t h2)
{
    int v1, v2;
    v1 = royal_flush(h1), v2 = royal_flush(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = straight_flush(h1), v2 = straight_flush(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = four_of_a_kind(h1), v2 = four_of_a_kind(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = full_house(h1), v2 = full_house(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = flush(h1), v2 = flush(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = straight(h1), v2 = straight(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = three_of_a_kind(h1), v2 = three_of_a_kind(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = two_pair(h1), v2 = two_pair(h2);
    if (v1 - v2)
        return v1 - v2;
    v1 = one_pair(h1), v2 = one_pair(h2);
    if (v1 - v2)
        return v1 - v2;
    std::array<int, 5> arr1;
    std::array<int, 5> arr2;
    for (int i = 0; i < 5; ++i)
        arr1[i] = VALU(h1[i]), arr2[i] = VALU(h2[i]);
    std::sort(arr1.rbegin(), arr1.rend());
    std::sort(arr2.rbegin(), arr2.rend());
    int i = 0;
    while (arr1[i] == arr2[i])
        ++i;
    v1 = arr1[i], v2 = arr2[i];
    return v1 - v2;
}

int main()
{
    std::ifstream ifs("c/054poker.txt");
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));
    auto hands = parse(content);
    int sum = 0;
    for (uint i = 0; i < hands.size() / 2; ++i)
        sum += cmp(hands[2 * i], hands[2 * i + 1]) > 0;
    std::cout << sum << std::endl;
}
