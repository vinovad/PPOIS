/**
 * @file ElectronicPDF.h
 * @brief ����� ��� ������ � ������������ �������� ����
 */

#ifndef ELECTRONICPDF_H
#define ELECTRONICPDF_H

#include "Audiobook.h"

 /**
  * @class ElectronicPDF
  * @brief ������������ ���������� � ������� ����������� � ����������� �����
  */
class ElectronicPDF {
private:
    bool has_pdf;               ///< ������� PDF ������
    Audiobook associatedAudiobook; ///< ��������������� ����������

public:
    /**
     * @brief ����������� � �����������
     * @param pdf ������� PDF ������
     * @param audio ��������������� ����������
     */
    ElectronicPDF(bool pdf, const Audiobook& audio);

    /**
     * @brief ����������� �� ���������
     */
    ElectronicPDF();

    /**
     * @brief ��������� ������� PDF ������
     * @return true ���� PDF ������ ��������, false � ��������� ������
     */
    bool has_pdf_version();

    /**
     * @brief �������� ������ ��������������� ����������
     * @return true ���� ���������� ��������, false � ��������� ������
     */
    bool get_AssociatedAudiobook();
};

#endif