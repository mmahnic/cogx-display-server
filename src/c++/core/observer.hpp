/*
 * Author: Marko Mahnič
 * Created: 2010-03-31
 *
 * © Copyright 2010 Marko Mahnič. 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef OBSERVER_ELHUP7YS
#define OBSERVER_ELHUP7YS

#include "ptrvector.hpp"
#include <IceUtil/RWRecMutex.h>


// CObserver to be used as a public member. Not to be used as a base class.
// Example:
//    class CLookAtMeObserver { public: void onDataChanged(CLookAtMe* where); };
//    class CLookAtMe {
//    public:
//       CObserver<CLookAtMeObserver> Observers;
//       void changeData() {
//          CLookAtMeObserver* pobs;
//          FOR_EACH(Observers, CLookAtMeObserver, pobs) pobs->onDataChanged(this);
//       }
//    };
template<class T>
class CObserver {
private:
   CPtrVector<T> m_Observers;
   IceUtil::RWRecMutex _observerMutex;

public:
   class ReadLock
   {
      CObserver* pOwner;
   public:
      ReadLock(CObserver& owner) { pOwner = &owner; pOwner->_observerMutex.readLock(); }
      ~ReadLock() { pOwner->_observerMutex.unlock(); }
   };

   void addObserver(T* pObserver)
   {
      IceUtil::RWRecMutex::WLock lock(_observerMutex);
      m_Observers.remove(pObserver);
      m_Observers.push_back(pObserver);
   }

   void removeObserver(T* pObserver)
   {
      IceUtil::RWRecMutex::WLock lock(_observerMutex);
      m_Observers.remove(pObserver);
   }

   void clearObservers(T* pObserver)
   {
      IceUtil::RWRecMutex::WLock lock(_observerMutex);
      m_Observers.clear();
   }

   void operator+=(T* pObserver)
   {
      addObserver(pObserver);
   }

   void operator-=(T* pObserver)
   {
      removeObserver(pObserver);
   }

   // Although these would better be const_iterator, iterator is required by FOR_EACH
   typename CPtrVector<T>::iterator begin()
   {
      return m_Observers.begin();
   }

   typename CPtrVector<T>::iterator end()
   {
      return m_Observers.end();
   }
};

#endif /* OBSERVER_ELHUP7YS */
