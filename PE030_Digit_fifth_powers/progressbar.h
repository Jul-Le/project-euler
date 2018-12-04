/*
 *  Julius L.
 *  01.12.2018
 */

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

class ProgressBar
{
public:
    ProgressBar(int len = 64);
    void update(float);
    void update(int a, int b) { update((float)a / (float)b); };
private:
    int m_length;
    int m_lastPct;
};
#endif // PROGRESSBAR_H
