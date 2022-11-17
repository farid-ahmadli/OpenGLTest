#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

#include <vector>
#include <QDomDocument>


typedef std::vector<double> DataArray;

typedef std::vector<std::string> StringArray;

class DataMatrix {

private:
    std::vector<DataArray> data;
    std::vector<StringArray> str_data;

public:
    DataMatrix() {}
    std::size_t size() const { return data.size(); }
    DataArray at(const std::size_t& i) const { return data.at(i); }
    void push_back(const DataArray& v, const StringArray& sv) { data.push_back(v); str_data.push_back(sv); }
    StringArray getLabels( const int& i ) const { return str_data.at(i); }
    DataArray operator[](const int& i) { return data[i]; }


      ///////////////////////////////////////////////////////
     //             SERIALIZING                           //
    ///////////////////////////////////////////////////////
    QDomElement serialize(QDomDocument& doc) {
        // dom element node for all lines
        QDomElement dataNode = doc.createElement("DataLines");

        // go through data lines
        for ( int i=0; i<data.size(); i++ ) {

            // create string by concatenating data
            QString str("");
            StringArray sa = str_data.at(i);
            for ( int j=0; j<sa.size(); j++ ) str.append( (sa.at(j) + " ").c_str() );

            // write data line as new Line tag
            QDomElement lineNode = doc.createElement("Line");
            lineNode.appendChild(doc.createTextNode(str));

            dataNode.appendChild(lineNode);
        }
        return dataNode;
    }

      ///////////////////////////////////////////////////////
     //             DESERIALIZING                         //
    ///////////////////////////////////////////////////////
    bool deserialize(const QDomElement& in) {
        if ( in.tagName().toUpper() == "DATALINES" ) {

            // initialize
            data.clear();
            str_data.clear();

            // get lines
            QDomNodeList list = in.elementsByTagName("Line");

            for ( int i=0; i<in.childNodes().size(); i++ ) {
                // convert to line element
                QDomElement lineNode(list.at(i).toElement());

                if ( lineNode.tagName().toUpper() == "LINE") {

                    // extract data by splitting it
                    QStringList values;
                    values = lineNode.text().split( QRegExp("(\\s+)"), QString::SkipEmptyParts );

                    // parse data and insert into arrays
                    DataArray v;
                    StringArray sv;
                    for ( int j=0; j<values.size(); j++ ) {
                        QString tmp = values.at(j);
                        bool ok;
                        sv.push_back( tmp.toStdString() );
                        v.push_back( tmp.toDouble(&ok) );
                    }

                    data.push_back(v);
                    str_data.push_back(sv);
                }
            }

            return true; // ok
        }
        return false; // something went wrong
    }
};

//
class PlotData
{

private:

    std::string m_title;
    std::string m_footer;
    std::string m_xAxisLabel;
    std::string m_yAxisLabel;
    std::string m_zAxisLabel;

    DataMatrix m_data; //data to be plotted

public:
    // getters and setters of private variables
    std::string getTitle() const { return m_title; }
    void setTitle(const std::string& value) { m_title = value; }
    std::string getFooter() const { return m_footer; }
    void setFooter(const std::string& value) { m_footer = value; }
    std::string getXAxisLabel() const { return m_xAxisLabel; }
    void setXAxisLabel(const std::string& value) { m_xAxisLabel = value; }
    std::string getYAxisLabel() const { return m_yAxisLabel; }
    void setYAxisLabel(const std::string& value) { m_yAxisLabel = value; }
    std::string getZAxisLabel() const { return m_zAxisLabel; }
    void setZAxisLabel(const std::string& value) { m_zAxisLabel = value; }

    DataMatrix getData() const { return m_data; }
    void setData(const DataMatrix& value) { m_data = value; }

      ///////////////////////////////////////////////////////
     //             SERIALIZING                           //
    ///////////////////////////////////////////////////////
    QDomElement serialize(QDomDocument& doc) {
        // Title
        QDomElement titleNode = doc.createElement("Title");
        titleNode.appendChild(doc.createTextNode(m_title.c_str()));

        // Footer
        QDomElement footerNode = doc.createElement("Footer");
        footerNode.appendChild(doc.createTextNode(m_footer.c_str()));

        // XAxis
        QDomElement xAxisNode = doc.createElement("XLabel");
        xAxisNode.appendChild(doc.createTextNode(m_xAxisLabel.c_str()));

        // YAxis
        QDomElement yAxisNode = doc.createElement("YLabel");
        yAxisNode.appendChild(doc.createTextNode(m_yAxisLabel.c_str()));

        // ZAxis
        QDomElement zAxisNode = doc.createElement("ZLabel");
        zAxisNode.appendChild(doc.createTextNode(m_zAxisLabel.c_str()));

        // Data
        QDomElement dataNode;
        dataNode = m_data.serialize(doc);

        // PlotData
        QDomElement plotDataNode = doc.createElement("PlotData");
        plotDataNode.appendChild(titleNode);
        plotDataNode.appendChild(footerNode);
        plotDataNode.appendChild(xAxisNode);
        plotDataNode.appendChild(yAxisNode);
        plotDataNode.appendChild(zAxisNode);
        plotDataNode.appendChild(dataNode);

        return plotDataNode;
    }


      ///////////////////////////////////////////////////////
     //             DESERIALIZING                         //
    ///////////////////////////////////////////////////////
    bool deserialize(const QDomElement& in) {
        if ( in.tagName().toUpper() == "PLOTDATA") {
            // Title
            m_title = in.firstChildElement("Title").text().toStdString();
            // Footer
            m_footer = in.firstChildElement("Footer").text().toStdString();
            // xAxisLabel
            m_xAxisLabel = in.firstChildElement("XLabel").text().toStdString();
            // yAxisLabel
            m_yAxisLabel = in.firstChildElement("YLabel").text().toStdString();
            // zAxisLabel
            m_zAxisLabel = in.firstChildElement("ZLabel").text().toStdString();
            // Data
            return m_data.deserialize( in.firstChildElement("DataLines") );
        }
        return false;
    }
};

//
struct LegendItem
{
public:
    LegendItem(const std::string& name, const long color):m_name(name), m_color(color)
    {}

    std::string name() const;

private:
    std::string m_name;
    long m_color;
};

//
class Legend
{

private:
    long m_bordercolor;
    long m_borderweight;
    int xPos, yPos;
    std::vector<LegendItem> m_items;

public:
    Legend() {}
    Legend(const long bcolor, const long bweight)
            :m_bordercolor(bcolor), m_borderweight(bweight) {}

    bool addItem(const LegendItem& li);
    bool delItem(const size_t pos);
    LegendItem item(const size_t pos) const;
    LegendItem& item(const size_t pos);
};

//
class Graph
{

public:
    enum Mode { LineGraph = 0, ScatterPlot2D, ScatterPlot3D, ScatterPlotContour3D, SurfacePlot, MeshPlot };
    enum ImageFormat { PngFormat = 0, JpegFormat, GifFormat };
    enum AxisType { xAxis = 0, yAxis, ZAxis };

private:
    Mode     m_mode;
    Legend   m_legend;
    PlotData m_plotdata;

public:
    Graph() {}
    Graph(const Graph& g) { this->m_mode = g.getMode();
        this->m_plotdata = g.getPlotData();
        this->m_legend = g.getLegend(); }

    // ++++++ MODE
    Mode getMode() const { return m_mode; }
    std::string getModeStr() const {
        switch(m_mode){
        case LineGraph: return "Line Graph";
        case ScatterPlot2D: return "2D Scatter Plot";
        case ScatterPlot3D: return "3D Scatter Plot";
        case ScatterPlotContour3D: return "3D Scatter Plot with Contour Map";
        case SurfacePlot: return "Surface Plot";
        case MeshPlot: return "Mesh Plot";
        };
        return "";
    }
    Mode getStrMode( const QString& value ) const {
        QString str = value.toUpper();
        if ( str == "LINE GRAPH" ) return LineGraph;
        if ( str == "2D SCATTER PLOT" ) return ScatterPlot2D;
        if ( str == "3D SCATTER PLOT" ) return ScatterPlot3D;
        if ( str == "3D SCATTER PLOT WITH CONTOUR MAP" ) return ScatterPlotContour3D;
        if ( str == "SURFACE PLOT" ) return SurfacePlot;
        if ( str == "MESH PLOT" ) return MeshPlot;
        return (Mode)0;
    }
    void setMode(const Mode& value) { m_mode = value; }
    // ------ MODE

    Legend getLegend() const { return m_legend; }
    void setLegend(const Legend& value) { m_legend = value; }
    PlotData getPlotData() const { return m_plotdata; }
    void setPlotData(const PlotData& value) { m_plotdata = value; }

      ///////////////////////////////////////////////////////
     //             SERIALIZING                           //
    ///////////////////////////////////////////////////////
    QDomElement serialize(QDomDocument& doc) {
        // Mode
        QDomElement modeNode = doc.createElement("Mode");
        modeNode.appendChild(doc.createTextNode(getModeStr().c_str()));

        // PlotData
        QDomElement plotDataNode = m_plotdata.serialize(doc);

        // Graph
        QDomElement graphNode = doc.createElement("Graph");
        graphNode.appendChild(modeNode);
        graphNode.appendChild(plotDataNode);

        return graphNode;
    }

      ///////////////////////////////////////////////////////
     //             DESERIALIZING                         //
    ///////////////////////////////////////////////////////
    bool deserialize(const QDomElement& in) {
        if ( in.tagName().toUpper() == "GRAPH") {
            // Mode
            m_mode = getStrMode(in.firstChildElement("Mode").text());

            // Plot Data
            m_plotdata.deserialize(in.firstChildElement("PlotData"));

            return true;
        }
        return false;
    }
};

#endif // DATA_STRUCT_H
