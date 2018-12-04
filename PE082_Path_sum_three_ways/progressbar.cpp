/*
 *  Julius L.
 *  Created 01.12.2018
 *  04.12.2018: Added destructor
 */

#include "progressbar.h"
#include <iostream>

ProgressBar::ProgressBar(int len) : m_length(len)
{
    m_lastPct = 0;
    update(0.0);
}

ProgressBar::~ProgressBar()
{
    std::cout << std::endl;
}

void ProgressBar::update(float pct)
{
    // Do not update if no visible progress
    if (pct * 100.f < m_lastPct)
        return;

    m_lastPct++;

    // How many ticks done
    int x = (int)(pct * (float)m_length);

    // Carriage return to show only one bar
    std::cout << "\r";
    std::cout << "[";

    for (int i = 0; i < x; i++)
    {
        std::cout << "=";
    }
    if (pct < 1.0)
        std::cout << ">";

    for (int i = 0; i < m_length - 1 - x; i++)
    {
        std::cout << " ";
    }
    std::cout << "] ";
    std::cout << (int)(pct * 100.f) << "%" << std::flush;
}
