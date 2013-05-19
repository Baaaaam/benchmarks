# local 
from matl_translate import JsonMaterialParser, CompositionError

# json/xml packages
try:
    import simplejson as json
except ImportError:
    import json
from lxml import etree

# test packages
from nose.tools import assert_equal, assert_raises

def test_recipe_translation():
    name,ntopes,xml_isotopes,json_isotopes,values = setup_constants()
    xml_node = setup_xml(name,ntopes,xml_isotopes,values)
    name, description = setup_json_rec(name,ntopes,json_isotopes,values)
    parser = JsonMaterialParser(name, description)
    material = parser.parse()
    assert_equal(etree.tostring(xml_node),etree.tostring(material.node))

def test_nonrecipe_translation():
    name,ntopes,xml_isotopes,json_isotopes,values = setup_constants()
    xml_node = setup_xml(name,ntopes,xml_isotopes,values)
    name, description = setup_json_non(name,ntopes,json_isotopes,values)
    parser = JsonMaterialParser(name, description)
    material = parser.parse()
    assert_equal(etree.tostring(xml_node),etree.tostring(material.node))

def test_raises():
    name, description = setup_json_throw()
    parser = JsonMaterialParser(name, description)
    assert_raises(CompositionError,parser.parse)

def setup_xml(name,ntopes,isotopes,values):
    root = etree.Element("recipe")
    elname = etree.SubElement(root,"name")
    elname.text = name
    elbasis = etree.SubElement(root,"basis")
    elbasis.text = "mass"
    for i in range(ntopes):
        eliso = etree.SubElement(root,"isotope")
        elid = etree.SubElement(eliso,"id")
        elid.text = isotopes[i]
        elval = etree.SubElement(eliso,"comp")
        elval.text = str(values[i])
    return root

def setup_json_rec(name,ntopes,isotopes,values):
    jisotopes = []
    for i in range(ntopes):
        jisotopes.append([isotopes[i],values[i]])
    obj = {name:{\
               "attributes":{"recipe":"true"},\
               "constraints":jisotopes\
          }}
    return name, obj[name]

def setup_json_non(name,ntopes,isotopes,values):
    jisotopes = []
    for i in range(ntopes):
        jisotopes.append([isotopes[i],values[i]])
    obj = {name:{\
               "attributes":{"recipe":"false","suggestedComposition":jisotopes},\
               "constraints":[]\
          }}
    return name, obj[name]

def setup_json_throw():
    name = "some_name"
    obj = {name:{\
            "attributes":{"recipe":"false"},\
            "constraints":[]\
          }}
    return name, obj[name]

def setup_constants():
    name = "a_name"
    ntopes = 2
    xml_isotopes = ["922350", "922380"]
    json_isotopes = ["U235", "U238"]
    values = [1e0, 2e0]
    return name,ntopes,xml_isotopes,json_isotopes,values

if __name__ == "__main__":
    name,ntopes,xml_isotopes,json_isotopes,values = \
        setup_constants()
    xml_node = setup_xml(name,ntopes,xml_isotopes,values)
    json_obj = setup_json(name,ntopes,json_isotopes,values)
    print etree.tostring(xml_node)
    print json.dumps(json_obj, indent = 4 * ' ')