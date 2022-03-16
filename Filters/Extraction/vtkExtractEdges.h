/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkExtractEdges.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkExtractEdges
 * @brief   extract cell edges from any type of data
 *
 * vtkExtractEdges is a filter to extract edges from a dataset. Edges
 * are extracted as lines or polylines.
 *
 * @sa
 * vtkFeatureEdges
 */

#ifndef vtkExtractEdges_h
#define vtkExtractEdges_h

#include "vtkFiltersExtractionModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkIncrementalPointLocator;

class VTKFILTERSEXTRACTION_EXPORT vtkExtractEdges : public vtkPolyDataAlgorithm
{
public:
  static vtkExtractEdges* New();
  vtkTypeMacro(vtkExtractEdges, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * Set / get a spatial locator for merging points. By
   * default an instance of vtkMergePoints is used.
   */
  void SetLocator(vtkIncrementalPointLocator* locator);
  vtkGetObjectMacro(Locator, vtkIncrementalPointLocator);
  ///@}

  /**
   * Create default locator. Used to create one when none is specified.
   */
  void CreateDefaultLocator();

  ///@{
  /**
   * Indicates that all of the points of the input mesh should exist in the output.
   */
  vtkSetMacro(UseAllPoints, bool);
  vtkGetMacro(UseAllPoints, bool);
  vtkBooleanMacro(UseAllPoints, bool);
  ///@}

  /**
   * Return MTime also considering the locator.
   */
  vtkMTimeType GetMTime() override;

protected:
  vtkExtractEdges();
  ~vtkExtractEdges() override;

  // Usual data generation method
  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  int NonLocatorExtraction(vtkDataSet* input, vtkPolyData* output);

  int FillInputPortInformation(int port, vtkInformation* info) override;

  vtkIncrementalPointLocator* Locator;

  bool UseAllPoints;

private:
  vtkExtractEdges(const vtkExtractEdges&) = delete;
  void operator=(const vtkExtractEdges&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
