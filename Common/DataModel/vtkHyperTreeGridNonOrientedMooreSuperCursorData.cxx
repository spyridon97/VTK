//------------------------------------------------------------------------------
// Super cursor traversal table to retrieve the child index for each cursor
// of the parent node. There are (3*f)^d entries in the table.
// d = 1 f = 2
VTK_ABI_NAMESPACE_BEGIN
static const unsigned int MooreChildCursorToChildTable12[6] = {
  1, 0, 1,
  0, 1, 0,
};
// d = 1 f = 3
static const unsigned int MooreChildCursorToChildTable13[9] = {
  2, 0, 1,
  0, 1, 2,
  1, 2, 0,
};
// d = 2 f = 2
static const unsigned int MooreChildCursorToChildTable22[36] = {
  3, 2, 3, 1, 0, 1, 3, 2, 3,
  2, 3, 2, 0, 1, 0, 2, 3, 2,
  1, 0, 1, 3, 2, 3, 1, 0, 1,
  0, 1, 0, 2, 3, 2, 0, 1, 0,
};
// d = 2 f = 3
static const unsigned int MooreChildCursorToChildTable23[81] = {
  8, 6, 7, 2, 0, 1, 5, 3, 4,
  6, 7, 8, 0, 1, 2, 3, 4, 5,
  7, 8, 6, 1, 2, 0, 4, 5, 3,
  2, 0, 1, 5, 3, 4, 8, 6, 7,
  0, 1, 2, 3, 4, 5, 6, 7, 8,
  1, 2, 0, 4, 5, 3, 7, 8, 6,
  5, 3, 4, 8, 6, 7, 2, 0, 1,
  3, 4, 5, 6, 7, 8, 0, 1, 2,
  4, 5, 3, 7, 8, 6, 1, 2, 0,
};

// d = 3 f = 2
static const unsigned int MooreChildCursorToChildTable32[216] = {
  7, 6, 7, 5, 4, 5, 7, 6, 7, 3, 2, 3, 1, 0, 1, 3, 2, 3, 7, 6, 7, 5, 4, 5, 7, 6, 7,
  6, 7, 6, 4, 5, 4, 6, 7, 6, 2, 3, 2, 0, 1, 0, 2, 3, 2, 6, 7, 6, 4, 5, 4, 6, 7, 6,
  5, 4, 5, 7, 6, 7, 5, 4, 5, 1, 0, 1, 3, 2, 3, 1, 0, 1, 5, 4, 5, 7, 6, 7, 5, 4, 5,
  4, 5, 4, 6, 7, 6, 4, 5, 4, 0, 1, 0, 2, 3, 2, 0, 1, 0, 4, 5, 4, 6, 7, 6, 4, 5, 4,
  3, 2, 3, 1, 0, 1, 3, 2, 3, 7, 6, 7, 5, 4, 5, 7, 6, 7, 3, 2, 3, 1, 0, 1, 3, 2, 3,
  2, 3, 2, 0, 1, 0, 2, 3, 2, 6, 7, 6, 4, 5, 4, 6, 7, 6, 2, 3, 2, 0, 1, 0, 2, 3, 2,
  1, 0, 1, 3, 2, 3, 1, 0, 1, 5, 4, 5, 7, 6, 7, 5, 4, 5, 1, 0, 1, 3, 2, 3, 1, 0, 1,
  0, 1, 0, 2, 3, 2, 0, 1, 0, 4, 5, 4, 6, 7, 6, 4, 5, 4, 0, 1, 0, 2, 3, 2, 0, 1, 0,
};

// d = 3 f = 3
static const unsigned int MooreChildCursorToChildTable33[729] = {
  26, 24, 25, 20, 18, 19, 23, 21, 22, 8, 6, 7, 2, 0, 1, 5, 3, 4, 17, 15, 16, 11, 9, 10, 14, 12, 13,
  24, 25, 26, 18, 19, 20, 21, 22, 23, 6, 7, 8, 0, 1, 2, 3, 4, 5, 15, 16, 17, 9, 10, 11, 12, 13, 14,
  25, 26, 24, 19, 20, 18, 22, 23, 21, 7, 8, 6, 1, 2, 0, 4, 5, 3, 16, 17, 15, 10, 11, 9, 13, 14, 12,
  20, 18, 19, 23, 21, 22, 26, 24, 25, 2, 0, 1, 5, 3, 4, 8, 6, 7, 11, 9, 10, 14, 12, 13, 17, 15, 16,
  18, 19, 20, 21, 22, 23, 24, 25, 26, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
  19, 20, 18, 22, 23, 21, 25, 26, 24, 1, 2, 0, 4, 5, 3, 7, 8, 6, 10, 11, 9, 13, 14, 12, 16, 17, 15,
  23, 21, 22, 26, 24, 25, 20, 18, 19, 5, 3, 4, 8, 6, 7, 2, 0, 1, 14, 12, 13, 17, 15, 16, 11, 9, 10,
  21, 22, 23, 24, 25, 26, 18, 19, 20, 3, 4, 5, 6, 7, 8, 0, 1, 2, 12, 13, 14, 15, 16, 17, 9, 10, 11,
  22, 23, 21, 25, 26, 24, 19, 20, 18, 4, 5, 3, 7, 8, 6, 1, 2, 0, 13, 14, 12, 16, 17, 15, 10, 11, 9,
  8, 6, 7, 2, 0, 1, 5, 3, 4, 17, 15, 16, 11, 9, 10, 14, 12, 13, 26, 24, 25, 20, 18, 19, 23, 21, 22,
  6, 7, 8, 0, 1, 2, 3, 4, 5, 15, 16, 17, 9, 10, 11, 12, 13, 14, 24, 25, 26, 18, 19, 20, 21, 22, 23,
  7, 8, 6, 1, 2, 0, 4, 5, 3, 16, 17, 15, 10, 11, 9, 13, 14, 12, 25, 26, 24, 19, 20, 18, 22, 23, 21,
  2, 0, 1, 5, 3, 4, 8, 6, 7, 11, 9, 10, 14, 12, 13, 17, 15, 16, 20, 18, 19, 23, 21, 22, 26, 24, 25,
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
  1, 2, 0, 4, 5, 3, 7, 8, 6, 10, 11, 9, 13, 14, 12, 16, 17, 15, 19, 20, 18, 22, 23, 21, 25, 26, 24,
  5, 3, 4, 8, 6, 7, 2, 0, 1, 14, 12, 13, 17, 15, 16, 11, 9, 10, 23, 21, 22, 26, 24, 25, 20, 18, 19,
  3, 4, 5, 6, 7, 8, 0, 1, 2, 12, 13, 14, 15, 16, 17, 9, 10, 11, 21, 22, 23, 24, 25, 26, 18, 19, 20,
  4, 5, 3, 7, 8, 6, 1, 2, 0, 13, 14, 12, 16, 17, 15, 10, 11, 9, 22, 23, 21, 25, 26, 24, 19, 20, 18,
  17, 15, 16, 11, 9, 10, 14, 12, 13, 26, 24, 25, 20, 18, 19, 23, 21, 22, 8, 6, 7, 2, 0, 1, 5, 3, 4,
  15, 16, 17, 9, 10, 11, 12, 13, 14, 24, 25, 26, 18, 19, 20, 21, 22, 23, 6, 7, 8, 0, 1, 2, 3, 4, 5,
  16, 17, 15, 10, 11, 9, 13, 14, 12, 25, 26, 24, 19, 20, 18, 22, 23, 21, 7, 8, 6, 1, 2, 0, 4, 5, 3,
  11, 9, 10, 14, 12, 13, 17, 15, 16, 20, 18, 19, 23, 21, 22, 26, 24, 25, 2, 0, 1, 5, 3, 4, 8, 6, 7,
  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 0, 1, 2, 3, 4, 5, 6, 7, 8,
  10, 11, 9, 13, 14, 12, 16, 17, 15, 19, 20, 18, 22, 23, 21, 25, 26, 24, 1, 2, 0, 4, 5, 3, 7, 8, 6,
  14, 12, 13, 17, 15, 16, 11, 9, 10, 23, 21, 22, 26, 24, 25, 20, 18, 19, 5, 3, 4, 8, 6, 7, 2, 0, 1,
  12, 13, 14, 15, 16, 17, 9, 10, 11, 21, 22, 23, 24, 25, 26, 18, 19, 20, 3, 4, 5, 6, 7, 8, 0, 1, 2,
  13, 14, 12, 16, 17, 15, 10, 11, 9, 22, 23, 21, 25, 26, 24, 19, 20, 18, 4, 5, 3, 7, 8, 6, 1, 2, 0,
};
static const unsigned int* MooreChildCursorToChildTable[3][2] = {
  {MooreChildCursorToChildTable12,
   MooreChildCursorToChildTable13},
  {MooreChildCursorToChildTable22,
   MooreChildCursorToChildTable23},
  {MooreChildCursorToChildTable32,
   MooreChildCursorToChildTable33}
};
//------------------------------------------------------------------------------
// Super cursor traversal table to go retrieve the child index for each cursor
// of the child node. There are (3*f)^d entries in the table.
//------------------------------------------------------------------------------
// d = 1 f = 2
static const unsigned int MooreChildCursorToParentCursorTable12[6] = {
  0, 1, 1,
  1, 1, 2,
};
// d = 1 f = 3
static const unsigned int MooreChildCursorToParentCursorTable13[9] = {
  0, 1, 1,
  1, 1, 1,
  1, 1, 2,
};
// d = 2 f = 2
static const unsigned int MooreChildCursorToParentCursorTable22[36] = {
  0, 1, 1, 3, 4, 4, 3, 4, 4,
  1, 1, 2, 4, 4, 5, 4, 4, 5,
  3, 4, 4, 3, 4, 4, 6, 7, 7,
  4, 4, 5, 4, 4, 5, 7, 7, 8,
};
// d = 2 f = 3
static const unsigned int MooreChildCursorToParentCursorTable23[81] = {
  0, 1, 1, 3, 4, 4, 3, 4, 4,
  1, 1, 1, 4, 4, 4, 4, 4, 4,
  1, 1, 2, 4, 4, 5, 4, 4, 5,
  3, 4, 4, 3, 4, 4, 3, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 5, 4, 4, 5, 4, 4, 5,
  3, 4, 4, 3, 4, 4, 6, 7, 7,
  4, 4, 4, 4, 4, 4, 7, 7, 7,
  4, 4, 5, 4, 4, 5, 7, 7, 8,
};

// d = 3 f = 2
static const unsigned int MooreChildCursorToParentCursorTable32[216] = {
  0, 1, 1, 3, 4, 4, 3, 4, 4, 9, 10, 10, 12, 13, 13, 12, 13, 13, 9, 10, 10, 12, 13, 13, 12, 13, 13,
  1, 1, 2, 4, 4, 5, 4, 4, 5, 10, 10, 11, 13, 13, 14, 13, 13, 14, 10, 10, 11, 13, 13, 14, 13, 13, 14,
  3, 4, 4, 3, 4, 4, 6, 7, 7, 12, 13, 13, 12, 13, 13, 15, 16, 16, 12, 13, 13, 12, 13, 13, 15, 16, 16,
  4, 4, 5, 4, 4, 5, 7, 7, 8, 13, 13, 14, 13, 13, 14, 16, 16, 17, 13, 13, 14, 13, 13, 14, 16, 16, 17,
  9, 10, 10, 12, 13, 13, 12, 13, 13, 9, 10, 10, 12, 13, 13, 12, 13, 13, 18, 19, 19, 21, 22, 22, 21, 22, 22,
  10, 10, 11, 13, 13, 14, 13, 13, 14, 10, 10, 11, 13, 13, 14, 13, 13, 14, 19, 19, 20, 22, 22, 23, 22, 22, 23,
  12, 13, 13, 12, 13, 13, 15, 16, 16, 12, 13, 13, 12, 13, 13, 15, 16, 16, 21, 22, 22, 21, 22, 22, 24, 25, 25,
  13, 13, 14, 13, 13, 14, 16, 16, 17, 13, 13, 14, 13, 13, 14, 16, 16, 17, 22, 22, 23, 22, 22, 23, 25, 25, 26,
};

// d = 3 f = 3
static const unsigned int MooreChildCursorToParentCursorTable33[729] = {
  0, 1, 1, 3, 4, 4, 3, 4, 4, 9, 10, 10, 12, 13, 13, 12, 13, 13, 9, 10, 10, 12, 13, 13, 12, 13, 13,
  1, 1, 1, 4, 4, 4, 4, 4, 4, 10, 10, 10, 13, 13, 13, 13, 13, 13, 10, 10, 10, 13, 13, 13, 13, 13, 13,
  1, 1, 2, 4, 4, 5, 4, 4, 5, 10, 10, 11, 13, 13, 14, 13, 13, 14, 10, 10, 11, 13, 13, 14, 13, 13, 14,
  3, 4, 4, 3, 4, 4, 3, 4, 4, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
  4, 4, 5, 4, 4, 5, 4, 4, 5, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14,
  3, 4, 4, 3, 4, 4, 6, 7, 7, 12, 13, 13, 12, 13, 13, 15, 16, 16, 12, 13, 13, 12, 13, 13, 15, 16, 16,
  4, 4, 4, 4, 4, 4, 7, 7, 7, 13, 13, 13, 13, 13, 13, 16, 16, 16, 13, 13, 13, 13, 13, 13, 16, 16, 16,
  4, 4, 5, 4, 4, 5, 7, 7, 8, 13, 13, 14, 13, 13, 14, 16, 16, 17, 13, 13, 14, 13, 13, 14, 16, 16, 17,
  9, 10, 10, 12, 13, 13, 12, 13, 13, 9, 10, 10, 12, 13, 13, 12, 13, 13, 9, 10, 10, 12, 13, 13, 12, 13, 13,
  10, 10, 10, 13, 13, 13, 13, 13, 13, 10, 10, 10, 13, 13, 13, 13, 13, 13, 10, 10, 10, 13, 13, 13, 13, 13, 13,
  10, 10, 11, 13, 13, 14, 13, 13, 14, 10, 10, 11, 13, 13, 14, 13, 13, 14, 10, 10, 11, 13, 13, 14, 13, 13, 14,
  12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13,
  13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
  13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14,
  12, 13, 13, 12, 13, 13, 15, 16, 16, 12, 13, 13, 12, 13, 13, 15, 16, 16, 12, 13, 13, 12, 13, 13, 15, 16, 16,
  13, 13, 13, 13, 13, 13, 16, 16, 16, 13, 13, 13, 13, 13, 13, 16, 16, 16, 13, 13, 13, 13, 13, 13, 16, 16, 16,
  13, 13, 14, 13, 13, 14, 16, 16, 17, 13, 13, 14, 13, 13, 14, 16, 16, 17, 13, 13, 14, 13, 13, 14, 16, 16, 17,
  9, 10, 10, 12, 13, 13, 12, 13, 13, 9, 10, 10, 12, 13, 13, 12, 13, 13, 18, 19, 19, 21, 22, 22, 21, 22, 22,
  10, 10, 10, 13, 13, 13, 13, 13, 13, 10, 10, 10, 13, 13, 13, 13, 13, 13, 19, 19, 19, 22, 22, 22, 22, 22, 22,
  10, 10, 11, 13, 13, 14, 13, 13, 14, 10, 10, 11, 13, 13, 14, 13, 13, 14, 19, 19, 20, 22, 22, 23, 22, 22, 23,
  12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 12, 13, 13, 21, 22, 22, 21, 22, 22, 21, 22, 22,
  13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 22, 22, 22, 22, 22, 22, 22, 22, 22,
  13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 13, 13, 14, 22, 22, 23, 22, 22, 23, 22, 22, 23,
  12, 13, 13, 12, 13, 13, 15, 16, 16, 12, 13, 13, 12, 13, 13, 15, 16, 16, 21, 22, 22, 21, 22, 22, 24, 25, 25,
  13, 13, 13, 13, 13, 13, 16, 16, 16, 13, 13, 13, 13, 13, 13, 16, 16, 16, 22, 22, 22, 22, 22, 22, 25, 25, 25,
  13, 13, 14, 13, 13, 14, 16, 16, 17, 13, 13, 14, 13, 13, 14, 16, 16, 17, 22, 22, 23, 22, 22, 23, 25, 25, 26,
};
static const unsigned int* MooreChildCursorToParentCursorTable[3][2] = {
  {MooreChildCursorToParentCursorTable12,
   MooreChildCursorToParentCursorTable13},
  {MooreChildCursorToParentCursorTable22,
   MooreChildCursorToParentCursorTable23},
  {MooreChildCursorToParentCursorTable32,
   MooreChildCursorToParentCursorTable33}
};
//------------------------------------------------------------------------------
// Corner/leaf traversal tables to retrieve the parent cursor indices of all
// leaves touching a given corner of the parent node.
//------------------------------------------------------------------------------
static const int CornerNeighborCursorsTable1D0[2] = {
   0, 1, };
static const int CornerNeighborCursorsTable1D1[2] = {
   1, 2, };
static const int* CornerNeighborCursorsTable1D[2] = {
  CornerNeighborCursorsTable1D0,
  CornerNeighborCursorsTable1D1,
};
static const int CornerNeighborCursorsTable2D0[4] = {
   0, 1, 3, 4, };
static const int CornerNeighborCursorsTable2D1[4] = {
   1, 2, 4, 5, };
static const int CornerNeighborCursorsTable2D2[4] = {
   3, 4, 6, 7, };
static const int CornerNeighborCursorsTable2D3[4] = {
   4, 5, 7, 8, };
static const int* CornerNeighborCursorsTable2D[4] = {
  CornerNeighborCursorsTable2D0,
  CornerNeighborCursorsTable2D1,
  CornerNeighborCursorsTable2D2,
  CornerNeighborCursorsTable2D3,
};
static const unsigned int CornerNeighborCursorsTable3D0[8] = {
   0, 1, 3, 4, 9, 10, 12, 13, };
static const unsigned int CornerNeighborCursorsTable3D1[8] = {
   1, 2, 4, 5, 10, 11, 13, 14, };
static const unsigned int CornerNeighborCursorsTable3D2[8] = {
   3, 4, 6, 7, 12, 13, 15, 16, };
static const unsigned int CornerNeighborCursorsTable3D3[8] = {
   4, 5, 7, 8, 13, 14, 16, 17, };
static const unsigned int CornerNeighborCursorsTable3D4[8] = {
   9, 10, 12, 13, 18, 19, 21, 22, };
static const unsigned int CornerNeighborCursorsTable3D5[8] = {
   10, 11, 13, 14, 19, 20, 22, 23, };
static const unsigned int CornerNeighborCursorsTable3D6[8] = {
   12, 13, 15, 16, 21, 22, 24, 25, };
static const unsigned int CornerNeighborCursorsTable3D7[8] = {
   13, 14, 16, 17, 22, 23, 25, 26, };
static const unsigned int* CornerNeighborCursorsTable3D[8] = {
  CornerNeighborCursorsTable3D0,
  CornerNeighborCursorsTable3D1,
  CornerNeighborCursorsTable3D2,
  CornerNeighborCursorsTable3D3,
  CornerNeighborCursorsTable3D4,
  CornerNeighborCursorsTable3D5,
  CornerNeighborCursorsTable3D6,
  CornerNeighborCursorsTable3D7,
};
//------------------------------------------------------------------------------
VTK_ABI_NAMESPACE_END
