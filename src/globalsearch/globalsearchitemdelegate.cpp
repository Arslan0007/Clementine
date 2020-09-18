/* This file is part of Clementine.
   Copyright 2012, David Sansome <me@davidsansome.com>

   Clementine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Clementine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Clementine.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "globalsearchitemdelegate.h"

#include "globalsearchview.h"

GlobalSearchItemDelegate::GlobalSearchItemDelegate(GlobalSearchView* view)
    : LibraryItemDelegate(view), view_(view) {}

void GlobalSearchItemDelegate::paint(QPainter* painter,
                                     const QStyleOptionViewItem& option,
                                     const QModelIndex& index) const {
  // Tell the view we painted this item so it can lazy load some art.
  const_cast<GlobalSearchView*>(view_)->LazyLoadArt(index);

  LibraryItemDelegate::paint(painter, option, index);
}
