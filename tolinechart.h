//***************************************************************************
/*
 * TOra - An Oracle Toolkit for DBA's and developers
 * Copyright (C) 2000 GlobeCom AB
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 *      As a special exception, you have permission to link this program
 *      with the Oracle Client libraries and distribute executables, as long
 *      as you follow the requirements of the GNU GPL in regard to all of the
 *      software in the executable aside from Oracle client libraries. You
 *      are also allowed to link this program with the Qt Non Commercial for
 *      Windows.
 *
 *      Specifically you are not permitted to link this program with the
 *      Qt/UNIX or Qt/Windows products of TrollTech. And you are not
 *      permitted to distribute binaries compiled against these libraries
 *      without written consent from GlobeCom AB. Observe that this does not
 *      disallow linking to the Qt Free Edition.
 *
 * All trademarks belong to their respective owners.
 *
 ****************************************************************************/

#ifndef __TOLINECHART_H
#define __TOLINECHART_H

#include <list>
#include <qwidget.h>

/** A widget that displays a linechart with optional background throbber (Not implemented yet).
 */

class toLineChart : public QWidget {
  Q_OBJECT

  list<list<double> > Values;
  list<QString> Labels;
  bool Legend;
  bool Throbber;
  int Grid;
  bool AxisText;
  double MinValue;
  bool MinAuto;
  double MaxValue;
  bool MaxAuto;
  QString MinAxis;
  QString MaxAxis;
  QString YPostfix;
  int Samples;
  bool AutoSamples;
  QString Title;

  static double round(double round,bool up);
public:
  /** Create a new linechart.
   * @param parent Parent widget.
   * @param name Name of widget.
   * @param f Widget flags.
   */
  toLineChart(QWidget *parent=NULL,const char *name=NULL,WFlags f=0);

  /** Specify if legend should be displayed to the right of the graph, default is on.
   * @param on Whether to display legend or not.
   */
  void showLegend(bool on)
  { Legend=on; update(); }
  /** Check if legend is displayed or not.
   * @return If legend is displayed or not.
   */
  bool legend(void) const
  { return Legend; }

  /** Set title of the chart. Set to empty string to not display title.
   * @param title Title of chart.
   */
  void setTitle(const QString &title=QString::null)
  { Title=title; update(); }
  /** Get title of chart.
   * @return Title of chart.
   */
  const QString &title(void)
  { return Title; }

  /** Specify if throbber should be displayed in the graph, default is off.
   * The throbber is a large bar in the background showing the most recent value more
   * pominently than the historical values.
   * @param on Whether to display throbber or not.
   */
  void showThrobber(bool on)
  { Throbber=on; update(); }
  /** Check if throbber is displayed or not.
   * @return If throbber is displayed or not.
   */
  bool throbber(void) const
  { return Throbber; }

  /** Specify if a grid should be displayed in the graph, default is on.
   * @param div Number of parts to divide grid into.
   */
  void showGrid(int div=0)
  { Grid=div; update(); }
  /** Check if grid is displayed or not.
   * @return Number of parts to divide grid into.
   */
  int grid(void) const
  { return Grid; }

  /** Specify if a y-axis legend should be displayed in the graph, default is on.
   * @param on Whether to display legend or not.
   */
  void showAxisLegend(bool on)
  { AxisText=on; update(); }
  /** Check if y-axis legend is displayed or not.
   * @return If legend is displayed or not.
   */
  bool axisLegend(void) const
  { return AxisText; }

  /** Set y postfix value. This will be appended to the values in the axis legend.
   * @param postfix The string to append.
   */
  void setYPostfix(const QString &postfix)
  { YPostfix=postfix; update(); }
  /** Set max value on y-axis to auto.
   */
  void setMaxValueAuto(void)
  { MaxAuto=true; update(); }
  /** Set min value on y-axis to auto.
   */
  void setMinValueAuto(void)
  { MinAuto=true; update(); }
  /** Set max value on y-axis.
   * @param val Max value on y-axis.
   */
  void setMaxValue(double maxVal)
  { MaxAuto=false; MaxValue=maxVal; update(); }
  /** Set min value on y-axis.
   * @param val Min value on y-axis.
   */
  void setMinValue(double minVal)
  { MinAuto=false; MinValue=minVal; update(); }
  /** Get minimum value on y-axis. Will not return the automatically determinned minimum value.
   * @return Minimum value on y-axis.
   */
  double minValue(void) const
  { return MinValue; }
  /** Get maximum value on y-axis. Will not return the automatically determinned maximum value.
   * @return Maximum value on y-axis.
   */
  double maxValue(void) const
  { return MaxValue; }

  /** Set the oldest and newest legend on the x-axis. Leave empty to not display any text
   * on the axises.
   * @param minAxis Left legend on axis.
   * @param maxAxis Right legend on axis.
   */
  void setAxisLegend(const QString &minAxis,const QString &maxAxis)
  { MaxAxis=maxAxis; MinAxis=minAxis; update(); }
  /** Get the legend of the left of the x-axis.
   * @return Legend of oldest x-axis value.
   */
  const QString minAxis(void) const
  { return MinAxis; }
  /** Get the legend of the right of the x-axis.
   * @return Legend of the most recent x-axis value.
   */
  const QString maxAxis(void) const
  { return MaxAxis; }

  /** Set the number of samples on the x-axis. Setting samples to -1 will keep enough samples
   * to display one for each pixel of the screen. More samples than that will never be used
   * regardless of this setting.
   * @param samples Number of samples.
   */
  void setSamples(int samples=-1);
  /** Get the maximum number of samples on the x-axis.
   * @return Max number of samples.
   */
  int samples(void) const
  { return Samples; }

  /** Set the labels on the chart lines.
   * @param labels Labels of the lines. Empty labels will not show up in the legend.
   */
  void setLabels(const list<QString> &labels)
  { Labels=labels; update(); }
  /** Get the labels of the chart lines.
   * @return List of labels.
   */
  list<QString> &labels(void)
  { return Labels; }

  /** Add a new value set to the chart.
   * @param value New values for charts (One for each line).
   */
  void addValues(list<double> &value);

  /** Get list of values.
   * @return Values in piechart.
   */
  list<list<double> > &values(void)
  { return Values; }

protected:
  /** Reimplemented for internal reasons.
   */
  virtual void paintEvent(QPaintEvent *e);
};

#endif
