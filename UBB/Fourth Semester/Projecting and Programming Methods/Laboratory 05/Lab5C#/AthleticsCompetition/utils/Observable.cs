﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AthleticsCompetition.utils
{
    public abstract class Observable
    {
        public abstract void AddObserver(Observer o);
        public abstract void NotifyObservers();
    }
}
